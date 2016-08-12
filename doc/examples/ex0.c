#include <stdio.h>
#include <tk.h>

#define clearscreen() printf("\033[2J")

void key_press(tkey_t k, void* p)
{
	(void)p;
	if(k == TK_CTRL_E)
		tk_finish();
	else if(k == TK_ENTER)
		printf("%c", (unsigned char)k);
	else if(tk_is_printable(k))
		printf("[%c]", (unsigned char)k);
	else if(k == TK_CTRL_L)
		clearscreen();
	else {
		printf("\n----\n");
		printf("Key code: %lu\t\t[%lx]\n", k, k);
		printf("try to print: %s\n", (char*)&k);
		printf("[Press CTRL+e to exit]\n");
	}
	fflush(stdout);
}

int main()
{

	tk_init();
	tk_bind_all_key(key_press, NULL);
	tk_wait();
	
	return 0;
}
