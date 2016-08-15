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

/** @file tk.h
  * Declarations of the libtk
  */

#ifndef __TK_H__
#define __TK_H__
#include <stdio.h>
#include <inttypes.h>
#include <sys/ioctl.h>

//codes
#define TK_NUL			0x00
#define TK_ALL_KEY		TK_NUL
#define TK_CTRL_A		0x01
#define TK_CTRL_B		0x02
#define TK_CTRL_C		0x03
#define TK_CTRL_D		0x04
#define TK_END_OF_FILE		TK_CTRL_D
#define TK_CTRL_E		0x05
#define TK_CTRL_F		0x06
#define TK_CTRL_G		0x07
#define TK_CTRL_H		0x08
#define TK_TAB			0x09
#define TK_ENTER		0x0a
#define TK_EOF			TK_ENTER
#define TK_CTRL_K		0x0b
#define TK_CTRL_M		0x0d
#define TK_CTRL_L		0x0c
#define TK_CTRL_N		0x0e
#define TK_CTRL_O		0x0f
#define TK_CTRL_P		0x10
#define TK_CTRL_Q		0x11
#define TK_CTRL_R		0x12
#define TK_CTRL_S		0x13
#define TK_CTRL_T		0x14
#define TK_CTRL_U		0x15
#define TK_CTRL_V		0x16
#define TK_CTRL_W		0x17
#define TK_CTRL_X		0x18
#define TK_CTRL_Y		0x19
#define TK_CTRL_Z		0x1a
#define TK_ESC			0x1b

// printables
#define TK_SPACE		0x20
#define TK_EXCLAMATIN_MARK	0x21
#define TK_QUOTATION_MARK	0x22
#define TK_NUMBER_SIGN		0x23
#define TK_DOLLAR		0x24
#define TK_PERCENT		0x25
#define TK_AMBERSAND		0x26
#define TK_APOSTROPHE		0x27
#define TK_PARENTHESIS_OPEN	0x28
#define TK_PARENTHESIS_CLOSE	0x29
#define TK_ASTERISK		0x2a
#define TK_PLUS			0x2b
#define TK_COMMA		0x2c
#define TK_MINUS		0x2d
#define TK_PERIOD		0x2e
#define TK_SLASH		0x2f
#define TK_0			0x30
#define TK_1			0x31
#define TK_2			0x32
#define TK_3			0x33
#define TK_4			0x34
#define TK_5			0x35
#define TK_6			0x36
#define TK_7			0x37
#define TK_8			0x38
#define TK_9			0x39
#define TK_COLON		0x3a
#define TK_SEMICOLON		0x3b
#define TK_LESS_THAN		0x3c
#define TK_EQUAL		0x3d
#define TK_GREATER_THAN		0x3e
#define TK_QUESTION_MARK	0x3f
#define TK_AT			0x40
#define TK_A			0x41
#define TK_B			0x42
#define TK_C			0x43
#define TK_D			0x44
#define TK_E			0x45
#define TK_F			0x46
#define TK_G			0x47
#define TK_H			0x48
#define TK_I			0x49
#define TK_J			0x4a
#define TK_K			0x4b
#define TK_L			0x4c
#define TK_M			0x4d
#define TK_N			0x4e
#define TK_O			0x4f
#define TK_P			0x50
#define TK_Q			0x51
#define TK_R			0x52
#define TK_S			0x53
#define TK_T			0x54
#define TK_U			0x55
#define TK_V			0x56
#define TK_W			0x57
#define TK_X			0x58
#define TK_Y			0x59
#define TK_Z			0x5a
#define TK_SQUARE_BRACKET_OPEN	0x5b
#define TK_BACKSLASH		0x5c
#define TK_SQUARE_BRACKET_CLOSE	0x5d
#define TK_CARET		0x5e
#define TK_UNDERSCORE		0x5f
#define TK_GRAVE_ACCENT		0x60
#define TK_a			0x61
#define TK_b			0x62
#define TK_c			0x63
#define TK_d			0x64
#define TK_e			0x65
#define TK_f			0x66
#define TK_g			0x67
#define TK_h			0x68
#define TK_i			0x69
#define TK_j			0x6a
#define TK_k			0x6b
#define TK_l			0x6c
#define TK_m			0x6d
#define TK_n			0x6e
#define TK_o			0x6f
#define TK_p			0x70
#define TK_q			0x71
#define TK_r			0x72
#define TK_s			0x73
#define TK_t			0x74
#define TK_u			0x75
#define TK_v			0x76
#define TK_w			0x77
#define TK_x			0x78
#define TK_y			0x79
#define TK_z			0x7a
#define TK_CURLY_BRACKET_OPEN	0x7b
#define TK_PIPE			0x7c
#define TK_CURLY_BRACKET_CLOSE	0x7d
#define TK_TILDE		0x7e

#define TK_BACKSPACE		0x7f

// extend keys (greater codes than ascii [255])
#define TK_F1			0x504f1b
#define TK_F2			0x514f1b
#define TK_F3			0x524f1b
#define TK_F4			0x534f1b
#define TK_F5			0x7e35315b1b
#define TK_F6			0x7e37315b1b
#define TK_F7			0x7e38315b1b
#define TK_F8			0x7e39315b1b
#define TK_F9			0x7e30325b1b
#define TK_F10			0x7e31325b1b
#define TK_F11			0x7e33325b1b
#define TK_F12			0x7e34325b1b
#define TK_UP			0x415b1b
#define TK_DOWN			0x425b1b
#define TK_RIGHT		0x435b1b
#define TK_LEFT			0x445b1b
#define TK_HOME			0x7e315b1b
#define TK_INSERT		0x7e325b1b
#define TK_DELETE		0x7e335b1b
#define TK_END			0x7e345b1b
#define TK_PAGE_DOWN		0x7e365b1b	
#define TK_PAGE_UP		0x7e355b1b
#define TK_CTRL_UP		0x414f1b
#define TK_CTRL_DOWN		0x424f1b
#define TK_CTRL_RIGHT		0x434f1b
#define TK_CTRL_LEFT		0x444f1b

// alt's (esc + code)
#define TK_ALT_(CODE)		((CODE<<8)|TK_ESC)
#define TK_ALT_0		0x301b
#define TK_ALT_1		0x311b
#define TK_ALT_2		0x321b
#define TK_ALT_3		0x331b
#define TK_ALT_4		0x341b
#define TK_ALT_5		0x351b
#define TK_ALT_6		0x361b
#define TK_ALT_7		0x371b
#define TK_ALT_8		0x381b
#define TK_ALT_9		0x391b
#define TK_ALT_A		0x411b
#define TK_ALT_B		0x421b
#define TK_ALT_C		0x431b
#define TK_ALT_D		0x441b
#define TK_ALT_E		0x451b
#define TK_ALT_F		0x461b
#define TK_ALT_G		0x471b
#define TK_ALT_H		0x481b
#define TK_ALT_I		0x491b
#define TK_ALT_J		0x4a1b
#define TK_ALT_K		0x4b1b
#define TK_ALT_L		0x4c1b
#define TK_ALT_M		0x4d1b
#define TK_ALT_N		0x4e1b
#define TK_ALT_O		0x4f1b
#define TK_ALT_P		0x501b
#define TK_ALT_Q		0x511b
#define TK_ALT_R		0x521b
#define TK_ALT_S		0x531b
#define TK_ALT_T		0x541b
#define TK_ALT_U		0x551b
#define TK_ALT_V		0x561b
#define TK_ALT_W		0x571b
#define TK_ALT_X		0x581b
#define TK_ALT_Y		0x591b
#define TK_ALT_Z		0x5a1b
#define TK_ALT_a		0x611b
#define TK_ALT_b		0x621b
#define TK_ALT_c		0x631b
#define TK_ALT_d		0x641b
#define TK_ALT_e		0x651b
#define TK_ALT_f		0x661b
#define TK_ALT_g		0x671b
#define TK_ALT_h		0x681b
#define TK_ALT_i		0x691b
#define TK_ALT_j		0x6a1b
#define TK_ALT_k		0x6b1b
#define TK_ALT_l		0x6c1b
#define TK_ALT_m		0x6d1b
#define TK_ALT_n		0x6e1b
#define TK_ALT_o		0x6f1b
#define TK_ALT_p		0x701b
#define TK_ALT_q		0x711b
#define TK_ALT_r		0x721b
#define TK_ALT_s		0x731b
#define TK_ALT_t		0x741b
#define TK_ALT_u		0x751b
#define TK_ALT_v		0x761b
#define TK_ALT_w		0x771b
#define TK_ALT_x		0x781b
#define TK_ALT_y		0x791b
#define TK_ALT_z		0x7a1b

#define TK_PRINTABLE_BEGIN	TK_SPACE
#define TK_PRINTABLE_END	TK_TILDE

typedef enum{
	TK_CURSOR_UP,
	TK_CURSOR_DOWN,
	TK_CURSOR_RIGHT,
	TK_CURSOR_LEFT,
	TK_CLEAR_SCREEN,
	TK_CLEAR_LINE_END,
	TK_CLEAR_LINE_BEGINNING,
	TK_CLEAR_WHOLE_LINE
}tk_util;

typedef uint64_t tkey_t;
typedef void (*bind_function)(tkey_t, void*);

void tk_init (void);
void tk_finish (void);
void tk_bind_key (tkey_t k, bind_function f, void* argument_data);
void tk_bind_all_key (bind_function f, void* argument_data);
void tk_bind_all_printable_key (bind_function f, void* argument_data);
int  tk_is_printable (tkey_t k);
void tk_wait (void);

void tk_cursor_move (size_t row, size_t col);
void tk_cursor_movement (tk_util movement, size_t n);
void tk_clear (tk_util clear_comm);
void tk_cursor_visible (int visible);
void tk_cursor_save(void);
void tk_cursor_restore(void);
void tk_cursor_position(size_t* row, size_t* col);
struct winsize tk_screen_size(void);

#endif // __TK_H__
