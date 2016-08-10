tk
--

libtk is a **t**erminal **k**eyboard bindings helper. This project is for my own fun, there are many mature alternatives like [ncurses](https://www.gnu.org/software/ncurses/). libtk does not have all the features that ncurses has, tk is minimalistic, small and simple. tk is just a helper to bind functions to keyboard, like in this code, where the keys Ctrl+L are binded with the function clear screen (common convention em cli/tui programs):

```c
#include <stdio.h>
#include <tk.h>

void clear_screen(void*)
{
	char clear [ 5 ] = { 27, '[', '2', 'J', 0 };
	printf ( "%s", clear );
}

int main()
{
	tk_init();

	tk_bind_key(TK_CTRL_L, clear_screen, NULL);

	tk_finish();

	return 0;
}
```

dependencies
------------

* [libgenerics](https://github.com/yudi-matsuzake/libgenerics);

install
-------

```shell
$ make
$ sudo make install
```

uninstall
---------

```shell
$ sudo make uninstall
```
