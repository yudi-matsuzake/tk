tk
--

libtk is a helper for **t**erminal **k**eyboard bindings. This project is for my own fun, there are many mature alternatives like [ncurses](https://www.gnu.org/software/ncurses/). libtk does not have all the features that ncurses has, tk is minimalistic, small and simple. tk is just a helper to bind functions to keyboard, like in this code, where the keys Ctrl+L are binded with the function clear screen (common convention em cli/tui programs):

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

unlicense
---------

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to [<http://unlicense.org/>](http://unlicense.org/)
