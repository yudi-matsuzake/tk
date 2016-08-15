/*
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * For more information, please refer to <http://unlicense.org/>
 */


/** @file tk.c
  * Implementations of the libtk
  */
#include <unistd.h>
#include <termios.h>
#include <pthread.h>
#include <signal.h>
#include <sys/select.h>

#include <generics/queue.h>
#include <generics/trie.h>
#include <generics/vector.h>

#include "tk.h"

/*----------------------------------------------------------------------*/
void initialize_tk_structures(void);
void* getchar_monitor_and_dispatch (void *d);
int process_escape(void);
void add_escape_sequence(char* seq, tkey_t k);
void sigint_handler (int sig);
void exec_queue(queue_t* bind_queue, tkey_t k);
void call_bind (tkey_t k);
/*----------------------------------------------------------------------*/

typedef struct tk_bind{
	bind_function function;
	void* argument;
}tk_bind;

struct termios old_term_attr;
struct termios new_term_attr;
struct termios escape_term_attr;

pthread_t getchar_monitor_thread;

trie_t bind;

int tk_pipe[2];

/*
 *--TK----------------------------------------------------------------
 */

/** Returns whether the key `k` is printable.
  *
  * @param k key tk code
  *
  * @return 1 if the string is printable, 0 otherwise.
  */
int tk_is_printable (tkey_t k)
{
	return  k == TK_TAB ||
		k == TK_ENTER ||
		(k >= TK_PRINTABLE_BEGIN && k <= TK_PRINTABLE_END);
}

/*
 * Handle with sigint signal. Default is call the Ctrl+C
 * bind function
 */
void sigint_handler (int sig){
	if( sig == SIGINT )
		call_bind(TK_CTRL_C);
}

/*
 * executes all the bind functions in the queue
 */
void exec_queue(queue_t* bind_queue, tkey_t k)
{
	if ( bind_queue ){
		/* call all binded functions */
		qnode_t *i;
		for(i = bind_queue->head; i!=NULL; i = i->next){
			tk_bind* b = i->data;

			if(b) b->function(k, b->argument);
		}
	}
}


/*
 * call the binds for the `k` key.
 */
void call_bind (tkey_t k)
{
	queue_t* bind_queue;

	/*
	 * call the binding for all keys
	 */
	tkey_t all_key = TK_ALL_KEY;
	bind_queue = trie_get_element(&bind, &all_key, sizeof(tkey_t));
	exec_queue(bind_queue, k);

	bind_queue = trie_get_element(&bind, &k, sizeof(tkey_t));
	exec_queue(bind_queue, k);
}

/*
 * initialize binded_function queue
 */
void initialize_tk_structures(void)
{
	trie_create(&bind, sizeof(queue_t));
}

/** Monitor the keys and dispatch to the bind functions.
  *
  * @param d data
  */
void* getchar_monitor_and_dispatch (void *d)
{

	/* just to kill warnings */
	(void)d;

	fd_set rfds;

	tkey_t k;
	FD_ZERO( &rfds );
	FD_SET(STDIN_FILENO, &rfds);
	FD_SET(tk_pipe[0], &rfds);
	
	while(select(tk_pipe[0]+1, &rfds, NULL, NULL, NULL) == 0);
	while(	(!FD_ISSET(tk_pipe[0], &rfds))				&&
		(FD_ISSET(STDIN_FILENO, &rfds))				&&
		(read(STDIN_FILENO, &k, sizeof(tkey_t)) > 0)){

		call_bind(k);

		k = 0;
		FD_ZERO( &rfds );
		FD_SET(STDIN_FILENO, &rfds);
		FD_SET(tk_pipe[0], &rfds);
		while (select(tk_pipe[0]+1, &rfds, NULL, NULL, NULL) == 0);
	}

	pthread_exit(NULL);
}

/** Initialize all the internal structures of the libtk.
  * This includes all the necessary changes in the terminal
  * instance with termios.h. The thread that will monitor
  * the key presses will be launched here, in `tk_init`.
  * 
  */
void tk_init (void)
{

	signal(SIGINT, sigint_handler);


	/*
	 * initialize the pipe that will be used
	 * by select to stop to "getchar"
	 */
	pipe(tk_pipe);

	/*
	 * turn off the echoing and the
	 * canonical mode
	 */
	tcgetattr(STDIN_FILENO, &old_term_attr);
	new_term_attr = old_term_attr;
	new_term_attr.c_lflag &= ~(ECHO | ICANON);
	escape_term_attr = new_term_attr;
	escape_term_attr.c_cc[VMIN] = 0;
	escape_term_attr.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &new_term_attr);

	initialize_tk_structures();

	/*
	 * Initiate the key monitor thread.
	 */
	pthread_create( &getchar_monitor_thread, NULL,
			getchar_monitor_and_dispatch, NULL);
}

/*
 * destroy the bind queues
 */
void destroy_bind_queues(tnode_t* node)
{
	if(node){
		int i;
		for ( i = 0; i<NBYTE ; i++ )
			destroy_bind_queues(node->children[i]);

		if(node->value)
			queue_destroy((queue_t*)node->value);
	}
}

/** Finish all internal structures of the libtk.
  */
void tk_finish (void)
{
	close(tk_pipe[1]);

	destroy_bind_queues( &bind.root );
	trie_destroy( &bind );

	tcsetattr(STDIN_FILENO, TCSANOW, &old_term_attr);

	if(!pthread_equal(getchar_monitor_thread, pthread_self()))
		pthread_join( getchar_monitor_thread, NULL );
	else
		pthread_exit(NULL);

}

/** Bind a key to a functions.
  * Bind the key `k` to a function `f` and will pass
  * to `f`.
  *
  * @param k			the key to bind
  * @param f			the function callback
  * @param argument_data	argument to pass to the function
  */
void tk_bind_key (
		tkey_t k,
		bind_function f,
		void* argument_data)
{

	tnode_t* node;
	node = trie_get_node_or_allocate(&bind, &k, sizeof(tkey_t));

	/*
	 * allocates the memory for the queue
	 */
	if(node->value == NULL){
		node->value = malloc(bind.member_size);
		queue_create((queue_t*)node->value, sizeof(tk_bind));
	}

	tk_bind b;
	b.function = f;
	b.argument = argument_data; 

	queue_enqueue((queue_t*)node->value, &b);
}

/** Bind all keys to the function `f`.
  *
  * @param f			the function callback
  * @param argument_data	argument to pass to the function
  */
void tk_bind_all_key (bind_function f, void* argument_data)
{
	tk_bind_key(TK_ALL_KEY, f, argument_data);
}

/** Bind all printable keys (charactere).
  * Does not bind the special keys, neither the escape keys.
  *
  * @param f			the function callback
  * @param argument_data	argument to pass to the function
  */
void tk_bind_all_printable_key (bind_function f, void* argument_data)
{
	int i;
	for( i=TK_PRINTABLE_BEGIN; i<=TK_PRINTABLE_END; i++ )
		tk_bind_key(i, f, argument_data);
	tk_bind_key(TK_ENTER, f, argument_data);
	tk_bind_key(TK_TAB, f, argument_data);
}

/** Wait until the tk thread exits.
  */
void tk_wait (void)
{
	pthread_join(getchar_monitor_thread, NULL);
}

/*
 * --UTILITIES-------------------------------------------------------
 */


/** moves the terminal cursor to the row `row` and column `col`
  */
void tk_cursor_move (size_t row, size_t col)
{
	fprintf(stdout, "\033[%zu;%zuH", row, col);
	fflush(stdout);
}

/** get the current cursor position and put in the memory location
  * pointed by `row` and `col`.
  */
void tk_cursor_position (size_t* row, size_t* col)
{
	struct termios t0, t1;

	tcgetattr(STDIN_FILENO, &t0);

	t1 = t0;
	t1.c_lflag &= ~(ECHO | ICANON);

	tcsetattr(STDIN_FILENO, TCSANOW, &t1);

	printf("\033[6n");
	fflush(stdout);

	scanf("\033[%zu;%zuR", row, col);
	fflush(stdout);

	tcsetattr(STDIN_FILENO, TCSANOW, &t0);
}

/** Writes the terminal width in the address pointed by `w`
  * and the terminal height in the address pointed by `w`.
  *
  */
struct winsize tk_screen_size (void)
{
	struct winsize winsiz;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &winsiz);
	return winsiz;
}

/**
  * move `n` times the cursor with the predefined cursor
  * movements:
  *
  * `TK_CURSOR_UP`
  * `TK_CURSOR_DOWN`
  * `TK_CURSOR_LEFT`
  * `TK_CURSOR_RIGHT`
  *
  */
void tk_cursor_movement (tk_util movement, size_t n)
{
	char* fmt;

	switch(movement){
	case TK_CURSOR_UP:
		fmt = "\033[%dA";
		break;
	case TK_CURSOR_DOWN:
		fmt = "\033[%dB";
		break;
	case TK_CURSOR_RIGHT:
		fmt = "\033[%dC";
		break;
	case TK_CURSOR_LEFT:
		fmt = "\033[%dD";
		break;
	default:
		return;
	}
	fprintf(stdout, fmt, n);
	fflush(stdout);
}

/**
  * clear the screen with `clear_comm` predefined
  * command. 
  *
  * `clear_comm` may have these values:
  *
  * `TK_CLEAR_SCREEN` clears the whole screen
  * `TK_CLEAR` clears from the cursor to the end of line
  * `TK_CLEAR` clears from the cursor to the beginning of line
  * `TK_CLEAR` clears the whole line
  */
void tk_clear (tk_util clear_comm)
{
	char* comm;
	switch(clear_comm){
	case TK_CLEAR_SCREEN:
		comm = "\033[2J";
		break;
	case TK_CLEAR_LINE_END:
		comm = "\033[K";
		break;
	case TK_CLEAR_LINE_BEGINNING:
		comm = "\033[1K";
		break;
	case TK_CLEAR_WHOLE_LINE:
		comm = "\033[2K";
		break;
	default:
		return;
	}

	fprintf(stdout, "%s", comm);
	fflush(stdout);
}

/**
  * sets the cursor visibility
  *
  * @param visible	whether the cursor is set to
  *			(1) visible or
  *			(0) invisible
  */
void tk_cursor_visible (int visible)
{
	char* comm;
	if(visible)
		comm = "\033[?25h";
	else
		comm = "\033[?25l";

	fprintf(stdout, "%s", comm);
	fflush(stdout);
}

/**
  * saves the cursor position
  */
void tk_cursor_save(void)
{
	fprintf(stdout, "\033[s");
	fflush(stdout);
}

/**
  * restores the cursor position
  */
void tk_cursor_restore(void)
{
	fprintf(stdout, "\033[u");
	fflush(stdout);
}
