#include <stdio.h>
#include <tk.h>

#define clearscreen() printf("\033[2J")

void key_press(key_t k, void* p)
{
	(void)p;
	if(k == TK_CTRL_E)
		tk_finish();
	else if(k == TK_ENTER)
		printf("%c", k);
	else if(tk_is_printable(k))
		printf("[%c]", k);
	else if(k == TK_CTRL_L)
		clearscreen();
	else
		printf("Press CTRL+e to exit\n");
	fflush(stdout);
}

int main()
{

	tk_init();
	tk_bind_all_key(key_press, NULL);
	tk_wait();
	
	return 0;
}
