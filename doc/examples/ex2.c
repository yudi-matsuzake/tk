#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>

#include <tk.h>

#define mvcursor(x, y) printf("\033[%d;%dH", x, y)
#define clearscreen() printf("\033[2J");

#define cursor_hide()	printf("\033[?25l")
#define cursor_show()	printf("\033[?25h")

int x = 0, y = 0;

void draw()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	mvcursor(w.ws_row/2 + x, w.ws_col/2 + y);
	clearscreen();
	printf("O");
	fflush(stdout);
}

void move_O(tkey_t k, void* ptr)
{
	switch(k){
	case TK_UP:
		x--;
		break;
	case TK_DOWN:
		x++;
		break;
	case TK_LEFT:
		y--;
		break;
	case TK_RIGHT:
		y++;
		break;
	}
	draw();
}


int main()
{

	tk_init();
	cursor_hide();
	tk_bind_key(TK_UP, move_O, NULL);
	tk_bind_key(TK_DOWN, move_O, NULL);
	tk_bind_key(TK_RIGHT, move_O, NULL);
	tk_bind_key(TK_LEFT, move_O, NULL);

	draw();
	sleep(100);

	tk_finish();

	cursor_show();
	return 0;
}
