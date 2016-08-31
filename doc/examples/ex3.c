#include <stdio.h>
#include <unistd.h>
#include <tk.h>

void cursor_move(tkey_t k, void* p)
{
	switch(k){
	case TK_j:
	case TK_J:
		tk_cursor_movement(TK_CURSOR_DOWN, 1);
		break;
	case TK_k:
	case TK_K:
		tk_cursor_movement(TK_CURSOR_UP, 1);
		break;
	case TK_h:
	case TK_H:
		tk_cursor_movement(TK_CURSOR_LEFT, 1);
		break;
	case TK_l:
	case TK_L:
		tk_cursor_movement(TK_CURSOR_RIGHT, 1);
		break;
	}
}

void quit(tkey_t k, void* exit)
{
	*(int*)exit = 1;
}

void cursor_visible(tkey_t k, void* p)
{
	long int visible = (int long)p;
	tk_cursor_visible(visible);
}

void clearscreen(tkey_t k, void* p){
	tk_clear(TK_CLEAR_SCREEN);
}

int main()
{
	tk_init();
	tk_clear(TK_CLEAR_SCREEN);


	tk_bind_key(TK_j, cursor_move, NULL);
	tk_bind_key(TK_J, cursor_move, NULL);
	tk_bind_key(TK_k, cursor_move, NULL);
	tk_bind_key(TK_K, cursor_move, NULL);
	tk_bind_key(TK_h, cursor_move, NULL);
	tk_bind_key(TK_H, cursor_move, NULL);
	tk_bind_key(TK_l, cursor_move, NULL);
	tk_bind_key(TK_L, cursor_move, NULL);

	int exit = 0;
	tk_bind_key(TK_CTRL_E, quit, &exit);

	tk_bind_key(TK_CTRL_H, cursor_visible, 0);
	tk_bind_key(TK_CTRL_X, cursor_visible, (void*)1);
	tk_bind_key(TK_CTRL_L, clearscreen, NULL);

	while(!exit){
		tk_cursor_save();
		tk_cursor_move(0, 0);
		struct winsize w = tk_screen_size();
		printf("%dx%d", w.ws_row, w.ws_col);
		tk_cursor_restore();
		printf("o");
		fflush(stdout);
		usleep(500000);
	}

	printf("\n");
	tk_finish();
	return 0;
}
