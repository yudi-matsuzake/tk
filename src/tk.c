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
void add_escape_sequence(char* seq, key_t k);
void sigint_handler (int sig);
void call_bind (key_t k);
/*----------------------------------------------------------------------*/

struct termios old_term_attr;
struct termios new_term_attr;
struct termios escape_term_attr;

pthread_t getchar_monitor_thread;

int tk_pipe[2];

queue_t binded_function[TK_N_KEY_BIND];
queue_t binded_argument[TK_N_KEY_BIND];

trie_t escape_sequences;

/** Returns whether the key `k` is printable.
  *
  * @param k key tk code
  *
  * @return 1 if the string is printable, 0 otherwise.
  */
int tk_is_printable (key_t k)
{
	return  k >= TK_PRINTABLE_BEGIN &&
		k <= TK_PRINTABLE_END;
}

/*
 * add escape sequences to the trie `escape_sequences`.
 */
void add_escape_sequence(char* seq, key_t k)
{
	trie_add_element(&escape_sequences, seq, strlen(seq), &k);
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
 * call the binds for the `k` key.
 */
void call_bind (key_t k)
{
	/* call all binded functions */
	if ( k < TK_N_KEY_BIND ){
		qnode_t *i, *j;
		for(	i = binded_function[k].head,
			j = binded_argument[k].head;
			i!=NULL && j!=NULL;
			i = i->next, j = j->next){
		
			bind_function* f = i->data;
			(*f)(k, j->data);
		}
	}
}

/*
 * initialize binded_function queue
 */
void initialize_tk_structures(void)
{
	int i;
	for ( i = 0; i<TK_N_KEY_BIND ; i++ ){
		queue_create(&binded_function[i], sizeof(bind_function));
		queue_create(&binded_argument[i], sizeof(void*));
	}

	trie_create(&escape_sequences, sizeof(key_t));

	add_escape_sequence("[A",	TK_UP);
	add_escape_sequence("[B",	TK_DOWN);
	add_escape_sequence("[C",	TK_RIGHT);
	add_escape_sequence("[D",	TK_LEFT);
	add_escape_sequence("[1~",	TK_HOME);
	add_escape_sequence("[15~",	TK_F5);
	add_escape_sequence("[17~",	TK_F6);
	add_escape_sequence("[18~",	TK_F7);
	add_escape_sequence("[19~",	TK_F8);
	add_escape_sequence("[2~",	TK_INSERT);
	add_escape_sequence("[20~",	TK_F9);
	add_escape_sequence("[21~",	TK_F10);
	add_escape_sequence("[23~",	TK_F11);
	add_escape_sequence("[24~",	TK_F12);
	add_escape_sequence("[3~",	TK_DELETE);
	add_escape_sequence("[4~",	TK_END);
	add_escape_sequence("[5~",	TK_PAGE_UP);
	add_escape_sequence("[6~",	TK_PAGE_DOWN);
	add_escape_sequence("OQ",	TK_F2);
	add_escape_sequence("OR",	TK_F3);
	add_escape_sequence("OS",	TK_F4);
	add_escape_sequence("OA",	TK_UP);
	add_escape_sequence("OB",	TK_DOWN);
	add_escape_sequence("OC",	TK_RIGHT);
	add_escape_sequence("OD",	TK_LEFT);
	add_escape_sequence("1",	TK_ALT_1);
	add_escape_sequence("2",	TK_ALT_2);
	add_escape_sequence("3",	TK_ALT_3);
	add_escape_sequence("4",	TK_ALT_4);
	add_escape_sequence("5",	TK_ALT_5);
	add_escape_sequence("6",	TK_ALT_6);
	add_escape_sequence("7",	TK_ALT_7);
	add_escape_sequence("8",	TK_ALT_8);
	add_escape_sequence("9",	TK_ALT_9);
	add_escape_sequence("A",	TK_ALT_A);
	add_escape_sequence("B",	TK_ALT_B);
	add_escape_sequence("C",	TK_ALT_C);
	add_escape_sequence("D",	TK_ALT_D);
	add_escape_sequence("E",	TK_ALT_E);
	add_escape_sequence("F",	TK_ALT_F);
	add_escape_sequence("G",	TK_ALT_G);
	add_escape_sequence("H",	TK_ALT_H);
	add_escape_sequence("I",	TK_ALT_I);
	add_escape_sequence("J",	TK_ALT_J);
	add_escape_sequence("K",	TK_ALT_K);
	add_escape_sequence("L",	TK_ALT_L);
	add_escape_sequence("M",	TK_ALT_M);
	add_escape_sequence("N",	TK_ALT_N);
	add_escape_sequence("O",	TK_ALT_O);
	add_escape_sequence("P",	TK_ALT_P);
	add_escape_sequence("Q",	TK_ALT_Q);
	add_escape_sequence("R",	TK_ALT_R);
	add_escape_sequence("S",	TK_ALT_S);
	add_escape_sequence("T",	TK_ALT_T);
	add_escape_sequence("U",	TK_ALT_U);
	add_escape_sequence("V",	TK_ALT_V);
	add_escape_sequence("W",	TK_ALT_W);
	add_escape_sequence("X",	TK_ALT_X);
	add_escape_sequence("Y",	TK_ALT_Y);
	add_escape_sequence("Z",	TK_ALT_Z);
	add_escape_sequence("a",	TK_ALT_a);
	add_escape_sequence("b",	TK_ALT_b);
	add_escape_sequence("c",	TK_ALT_c);
	add_escape_sequence("d",	TK_ALT_d);
	add_escape_sequence("e",	TK_ALT_e);
	add_escape_sequence("f",	TK_ALT_f);
	add_escape_sequence("g",	TK_ALT_g);
	add_escape_sequence("h",	TK_ALT_h);
	add_escape_sequence("i",	TK_ALT_i);
	add_escape_sequence("j",	TK_ALT_j);
	add_escape_sequence("k",	TK_ALT_k);
	add_escape_sequence("l",	TK_ALT_l);
	add_escape_sequence("m",	TK_ALT_m);
	add_escape_sequence("n",	TK_ALT_n);
	add_escape_sequence("o",	TK_ALT_o);
	add_escape_sequence("p",	TK_ALT_p);
	add_escape_sequence("q",	TK_ALT_q);
	add_escape_sequence("r",	TK_ALT_r);
	add_escape_sequence("s",	TK_ALT_s);
	add_escape_sequence("t",	TK_ALT_t);
	add_escape_sequence("u",	TK_ALT_u);
	add_escape_sequence("v",	TK_ALT_v);
	add_escape_sequence("w",	TK_ALT_w);
	add_escape_sequence("x",	TK_ALT_x);
	add_escape_sequence("y",	TK_ALT_y);
	add_escape_sequence("z",	TK_ALT_z);
}

/*
 * will process the keyseq string
 */
int process_escape(void)
{
	int c = TK_ESC;
	tcsetattr(STDIN_FILENO, TCSANOW, &escape_term_attr);

	char newc;
	vector_t key_seq;
	vector_create( &key_seq, 0, sizeof(char) );
	while(read(STDIN_FILENO, &newc, sizeof(char))){
		vector_add(&key_seq, &newc);
	}

	if ( key_seq.size ){
		newc = '\0';
		vector_add(&key_seq, &newc);

		key_t* k;
		k = trie_get_element(	&escape_sequences,
					key_seq.data,
					strlen(key_seq.data));
		
		if(k)
			c = *k;
	}

	vector_destroy( &key_seq );
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term_attr);
	return c;
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

	int c;
	FD_ZERO( &rfds );
	FD_SET(STDIN_FILENO, &rfds);
	FD_SET(tk_pipe[0], &rfds);
	
	while(select(tk_pipe[0]+1, &rfds, NULL, NULL, NULL) == 0);
	while(	(!FD_ISSET(tk_pipe[0], &rfds))				&&
		(FD_ISSET(STDIN_FILENO, &rfds))				&&
		(read(STDIN_FILENO, &c, sizeof(char) > 0))){

		if(c == TK_ESC)
			c = process_escape();

		call_bind(c);

		c = 0;
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

/** Finish all internal structures of the libtk.
  */
void tk_finish (void)
{
	close(tk_pipe[1]);

	int i;
	for ( i = 0; i<TK_N_KEY_BIND ; i++ ){
		queue_destroy( &binded_function[i] );
		queue_destroy( &binded_argument[i] );
	}

	trie_destroy( &escape_sequences );

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
		key_t k,
		bind_function f,
		void* argument_data)
{
	if(f){
		queue_enqueue(&binded_function[k], &f);
		queue_enqueue(&binded_argument[k], &argument_data);
	}
}

/** Bind all keys to the function `f`.
  *
  * @param f			the function callback
  * @param argument_data	argument to pass to the function
  */
void tk_bind_all_key (bind_function f, void* argument_data)
{
	int i;
	for ( i = 0; i<TK_N_KEY_BIND ; i++ )
		tk_bind_key(i, f, argument_data);

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
}

/** Wait until the tk thread exits.
  */
void tk_wait (void)
{
	pthread_join(getchar_monitor_thread, NULL);
}
