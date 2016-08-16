#include <stdio.h>
#include <tk.h>
#define STR(X) #X "\n"

void fbind(tkey_t k, void* p)
{
	switch(k){
		case TK_NUL:
			printf(STR(TK_NUL));
			break;
		case TK_CTRL_A:
			printf(STR(TK_CTRL_A));
			break;
		case TK_ALT_(TK_CTRL_A):
			printf(STR(ALT + TK_CTRL_A));
			break;
		case TK_CTRL_B:
			printf(STR(TK_CTRL_B));
			break;
		case TK_ALT_(TK_CTRL_B):
			printf(STR(ALT + TK_CTRL_B));
			break;
		case TK_CTRL_C:
			printf(STR(TK_CTRL_C));
			break;
		case TK_ALT_(TK_CTRL_C):
			printf(STR(ALT + TK_CTRL_C));
			break;
		case TK_CTRL_D:
			printf(STR(TK_CTRL_D));
			break;
		case TK_ALT_(TK_CTRL_D):
			printf(STR(ALT + TK_CTRL_D));
			break;
		case TK_CTRL_E:
			printf(STR(TK_CTRL_E));
			break;
		case TK_ALT_(TK_CTRL_E):
			printf(STR(ALT + TK_CTRL_E));
			break;
		case TK_CTRL_F:
			printf(STR(TK_CTRL_F));
			break;
		case TK_ALT_(TK_CTRL_F):
			printf(STR(ALT + TK_CTRL_F));
			break;
		case TK_CTRL_G:
			printf(STR(TK_CTRL_G));
			break;
		case TK_ALT_(TK_CTRL_G):
			printf(STR(ALT + TK_CTRL_G));
			break;
		case TK_CTRL_H:
			printf(STR(TK_CTRL_H));
			break;
		case TK_ALT_(TK_CTRL_H):
			printf(STR(ALT + TK_CTRL_H));
			break;
		case TK_TAB:
			printf(STR(TK_TAB));
			break;
		case TK_ALT_(TK_TAB):
			printf(STR(ALT + TK_TAB));
			break;
		case TK_ENTER:
			printf(STR(TK_ENTER));
			break;
		case TK_ALT_(TK_ENTER):
			printf(STR(ALT + TK_ENTER));
			break;
		case TK_CTRL_K:
			printf(STR(TK_CTRL_K));
			break;
		case TK_ALT_(TK_CTRL_K):
			printf(STR(ALT + TK_CTRL_K));
			break;
		case TK_CTRL_M:
			printf(STR(TK_CTRL_M));
			break;
		case TK_ALT_(TK_CTRL_M):
			printf(STR(ALT + TK_CTRL_M));
			break;
		case TK_CTRL_L:
			printf(STR(TK_CTRL_L));
			break;
		case TK_ALT_(TK_CTRL_L):
			printf(STR(ALT + TK_CTRL_L));
			break;
		case TK_CTRL_N:
			printf(STR(TK_CTRL_N));
			break;
		case TK_ALT_(TK_CTRL_N):
			printf(STR(ALT + TK_CTRL_N));
			break;
		case TK_CTRL_O:
			printf(STR(TK_CTRL_O));
			break;
		case TK_ALT_(TK_CTRL_O):
			printf(STR(ALT + TK_CTRL_O));
			break;
		case TK_CTRL_P:
			printf(STR(TK_CTRL_P));
			break;
		case TK_ALT_(TK_CTRL_P):
			printf(STR(ALT + TK_CTRL_P));
			break;
		case TK_CTRL_Q:
			printf(STR(TK_CTRL_Q));
			break;
		case TK_ALT_(TK_CTRL_Q):
			printf(STR(ALT + TK_CTRL_Q));
			break;
		case TK_CTRL_R:
			printf(STR(TK_CTRL_R));
			break;
		case TK_ALT_(TK_CTRL_R):
			printf(STR(ALT + TK_CTRL_R));
			break;
		case TK_CTRL_S:
			printf(STR(TK_CTRL_S));
			break;
		case TK_ALT_(TK_CTRL_S):
			printf(STR(ALT + TK_CTRL_S));
			break;
		case TK_CTRL_T:
			printf(STR(TK_CTRL_T));
			break;
		case TK_ALT_(TK_CTRL_T):
			printf(STR(ALT + TK_CTRL_T));
			break;
		case TK_CTRL_U:
			printf(STR(TK_CTRL_U));
			break;
		case TK_ALT_(TK_CTRL_U):
			printf(STR(ALT + TK_CTRL_U));
			break;
		case TK_CTRL_V:
			printf(STR(TK_CTRL_V));
			break;
		case TK_ALT_(TK_CTRL_V):
			printf(STR(ALT + TK_CTRL_V));
			break;
		case TK_CTRL_W:
			printf(STR(TK_CTRL_W));
			break;
		case TK_ALT_(TK_CTRL_W):
			printf(STR(ALT + TK_CTRL_W));
			break;
		case TK_CTRL_X:
			printf(STR(TK_CTRL_X));
			break;
		case TK_ALT_(TK_CTRL_X):
			printf(STR(ALT + TK_CTRL_X));
			break;
		case TK_CTRL_Y:
			printf(STR(TK_CTRL_Y));
			break;
		case TK_ALT_(TK_CTRL_Y):
			printf(STR(ALT + TK_CTRL_Y));
			break;
		case TK_CTRL_Z:
			printf(STR(TK_CTRL_Z));
			break;
		case TK_ALT_(TK_CTRL_Z):
			printf(STR(ALT + TK_CTRL_Z));
			break;
		case TK_ESC:
			printf(STR(TK_ESC));
			break;
		case TK_ALT_(TK_ESC):
			printf(STR(ALT + TK_ESC));
			break;
		case TK_SPACE:
			printf(STR(TK_SPACE));
			break;
		case TK_ALT_(TK_SPACE):
			printf(STR(ALT + TK_SPACE));
			break;
		case TK_EXCLAMATIN_MARK:
			printf(STR(TK_EXCLAMATIN_MARK));
			break;
		case TK_ALT_(TK_EXCLAMATIN_MARK):
			printf(STR(ALT + TK_EXCLAMATIN_MARK));
			break;
		case TK_QUOTATION_MARK:
			printf(STR(TK_QUOTATION_MARK));
			break;
		case TK_ALT_(TK_QUOTATION_MARK):
			printf(STR(ALT + TK_QUOTATION_MARK));
			break;
		case TK_NUMBER_SIGN:
			printf(STR(TK_NUMBER_SIGN));
			break;
		case TK_ALT_(TK_NUMBER_SIGN):
			printf(STR(ALT + TK_NUMBER_SIGN));
			break;
		case TK_DOLLAR:
			printf(STR(TK_DOLLAR));
			break;
		case TK_ALT_(TK_DOLLAR):
			printf(STR(ALT + TK_DOLLAR));
			break;
		case TK_PERCENT:
			printf(STR(TK_PERCENT));
			break;
		case TK_ALT_(TK_PERCENT):
			printf(STR(ALT + TK_PERCENT));
			break;
		case TK_AMBERSAND:
			printf(STR(TK_AMBERSAND));
			break;
		case TK_ALT_(TK_AMBERSAND):
			printf(STR(ALT + TK_AMBERSAND));
			break;
		case TK_APOSTROPHE:
			printf(STR(TK_APOSTROPHE));
			break;
		case TK_ALT_(TK_APOSTROPHE):
			printf(STR(ALT + TK_APOSTROPHE));
			break;
		case TK_PARENTHESIS_OPEN:
			printf(STR(TK_PARENTHESIS_OPEN));
			break;
		case TK_ALT_(TK_PARENTHESIS_OPEN):
			printf(STR(ALT + TK_PARENTHESIS_OPEN));
			break;
		case TK_PARENTHESIS_CLOSE:
			printf(STR(TK_PARENTHESIS_CLOSE));
			break;
		case TK_ALT_(TK_PARENTHESIS_CLOSE):
			printf(STR(ALT + TK_PARENTHESIS_CLOSE));
			break;
		case TK_ASTERISK:
			printf(STR(TK_ASTERISK));
			break;
		case TK_ALT_(TK_ASTERISK):
			printf(STR(ALT + TK_ASTERISK));
			break;
		case TK_PLUS:
			printf(STR(TK_PLUS));
			break;
		case TK_ALT_(TK_PLUS):
			printf(STR(ALT + TK_PLUS));
			break;
		case TK_COMMA:
			printf(STR(TK_COMMA));
			break;
		case TK_ALT_(TK_COMMA):
			printf(STR(ALT + TK_COMMA));
			break;
		case TK_MINUS:
			printf(STR(TK_MINUS));
			break;
		case TK_ALT_(TK_MINUS):
			printf(STR(ALT + TK_MINUS));
			break;
		case TK_PERIOD:
			printf(STR(TK_PERIOD));
			break;
		case TK_ALT_(TK_PERIOD):
			printf(STR(ALT + TK_PERIOD));
			break;
		case TK_SLASH:
			printf(STR(TK_SLASH));
			break;
		case TK_ALT_(TK_SLASH):
			printf(STR(ALT + TK_SLASH));
			break;
		case TK_0:
			printf(STR(TK_0));
			break;
		case TK_ALT_(TK_0):
			printf(STR(ALT + TK_0));
			break;
		case TK_1:
			printf(STR(TK_1));
			break;
		case TK_ALT_(TK_1):
			printf(STR(ALT + TK_1));
			break;
		case TK_2:
			printf(STR(TK_2));
			break;
		case TK_ALT_(TK_2):
			printf(STR(ALT + TK_2));
			break;
		case TK_3:
			printf(STR(TK_3));
			break;
		case TK_ALT_(TK_3):
			printf(STR(ALT + TK_3));
			break;
		case TK_4:
			printf(STR(TK_4));
			break;
		case TK_ALT_(TK_4):
			printf(STR(ALT + TK_4));
			break;
		case TK_5:
			printf(STR(TK_5));
			break;
		case TK_ALT_(TK_5):
			printf(STR(ALT + TK_5));
			break;
		case TK_6:
			printf(STR(TK_6));
			break;
		case TK_ALT_(TK_6):
			printf(STR(ALT + TK_6));
			break;
		case TK_7:
			printf(STR(TK_7));
			break;
		case TK_ALT_(TK_7):
			printf(STR(ALT + TK_7));
			break;
		case TK_8:
			printf(STR(TK_8));
			break;
		case TK_ALT_(TK_8):
			printf(STR(ALT + TK_8));
			break;
		case TK_9:
			printf(STR(TK_9));
			break;
		case TK_ALT_(TK_9):
			printf(STR(ALT + TK_9));
			break;
		case TK_COLON:
			printf(STR(TK_COLON));
			break;
		case TK_ALT_(TK_COLON):
			printf(STR(ALT + TK_COLON));
			break;
		case TK_SEMICOLON:
			printf(STR(TK_SEMICOLON));
			break;
		case TK_ALT_(TK_SEMICOLON):
			printf(STR(ALT + TK_SEMICOLON));
			break;
		case TK_LESS_THAN:
			printf(STR(TK_LESS_THAN));
			break;
		case TK_ALT_(TK_LESS_THAN):
			printf(STR(ALT + TK_LESS_THAN));
			break;
		case TK_EQUAL:
			printf(STR(TK_EQUAL));
			break;
		case TK_ALT_(TK_EQUAL):
			printf(STR(ALT + TK_EQUAL));
			break;
		case TK_GREATER_THAN:
			printf(STR(TK_GREATER_THAN));
			break;
		case TK_ALT_(TK_GREATER_THAN):
			printf(STR(ALT + TK_GREATER_THAN));
			break;
		case TK_QUESTION_MARK:
			printf(STR(TK_QUESTION_MARK));
			break;
		case TK_ALT_(TK_QUESTION_MARK):
			printf(STR(ALT + TK_QUESTION_MARK));
			break;
		case TK_AT:
			printf(STR(TK_AT));
			break;
		case TK_ALT_(TK_AT):
			printf(STR(ALT + TK_AT));
			break;
		case TK_A:
			printf(STR(TK_A));
			break;
		case TK_ALT_(TK_A):
			printf(STR(ALT + TK_A));
			break;
		case TK_B:
			printf(STR(TK_B));
			break;
		case TK_ALT_(TK_B):
			printf(STR(ALT + TK_B));
			break;
		case TK_C:
			printf(STR(TK_C));
			break;
		case TK_ALT_(TK_C):
			printf(STR(ALT + TK_C));
			break;
		case TK_D:
			printf(STR(TK_D));
			break;
		case TK_ALT_(TK_D):
			printf(STR(ALT + TK_D));
			break;
		case TK_E:
			printf(STR(TK_E));
			break;
		case TK_ALT_(TK_E):
			printf(STR(ALT + TK_E));
			break;
		case TK_F:
			printf(STR(TK_F));
			break;
		case TK_ALT_(TK_F):
			printf(STR(ALT + TK_F));
			break;
		case TK_G:
			printf(STR(TK_G));
			break;
		case TK_ALT_(TK_G):
			printf(STR(ALT + TK_G));
			break;
		case TK_H:
			printf(STR(TK_H));
			break;
		case TK_ALT_(TK_H):
			printf(STR(ALT + TK_H));
			break;
		case TK_I:
			printf(STR(TK_I));
			break;
		case TK_ALT_(TK_I):
			printf(STR(ALT + TK_I));
			break;
		case TK_J:
			printf(STR(TK_J));
			break;
		case TK_ALT_(TK_J):
			printf(STR(ALT + TK_J));
			break;
		case TK_K:
			printf(STR(TK_K));
			break;
		case TK_ALT_(TK_K):
			printf(STR(ALT + TK_K));
			break;
		case TK_L:
			printf(STR(TK_L));
			break;
		case TK_ALT_(TK_L):
			printf(STR(ALT + TK_L));
			break;
		case TK_M:
			printf(STR(TK_M));
			break;
		case TK_ALT_(TK_M):
			printf(STR(ALT + TK_M));
			break;
		case TK_N:
			printf(STR(TK_N));
			break;
		case TK_ALT_(TK_N):
			printf(STR(ALT + TK_N));
			break;
		case TK_O:
			printf(STR(TK_O));
			break;
		case TK_ALT_(TK_O):
			printf(STR(ALT + TK_O));
			break;
		case TK_P:
			printf(STR(TK_P));
			break;
		case TK_ALT_(TK_P):
			printf(STR(ALT + TK_P));
			break;
		case TK_Q:
			printf(STR(TK_Q));
			break;
		case TK_ALT_(TK_Q):
			printf(STR(ALT + TK_Q));
			break;
		case TK_R:
			printf(STR(TK_R));
			break;
		case TK_ALT_(TK_R):
			printf(STR(ALT + TK_R));
			break;
		case TK_S:
			printf(STR(TK_S));
			break;
		case TK_ALT_(TK_S):
			printf(STR(ALT + TK_S));
			break;
		case TK_T:
			printf(STR(TK_T));
			break;
		case TK_ALT_(TK_T):
			printf(STR(ALT + TK_T));
			break;
		case TK_U:
			printf(STR(TK_U));
			break;
		case TK_ALT_(TK_U):
			printf(STR(ALT + TK_U));
			break;
		case TK_V:
			printf(STR(TK_V));
			break;
		case TK_ALT_(TK_V):
			printf(STR(ALT + TK_V));
			break;
		case TK_W:
			printf(STR(TK_W));
			break;
		case TK_ALT_(TK_W):
			printf(STR(ALT + TK_W));
			break;
		case TK_X:
			printf(STR(TK_X));
			break;
		case TK_ALT_(TK_X):
			printf(STR(ALT + TK_X));
			break;
		case TK_Y:
			printf(STR(TK_Y));
			break;
		case TK_ALT_(TK_Y):
			printf(STR(ALT + TK_Y));
			break;
		case TK_Z:
			printf(STR(TK_Z));
			break;
		case TK_ALT_(TK_Z):
			printf(STR(ALT + TK_Z));
			break;
		case TK_SQUARE_BRACKET_OPEN:
			printf(STR(TK_SQUARE_BRACKET_OPEN));
			break;
		case TK_ALT_(TK_SQUARE_BRACKET_OPEN):
			printf(STR(ALT + TK_SQUARE_BRACKET_OPEN));
			break;
		case TK_BACKSLASH:
			printf(STR(TK_BACKSLASH));
			break;
		case TK_ALT_(TK_BACKSLASH):
			printf(STR(ALT + TK_BACKSLASH));
			break;
		case TK_SQUARE_BRACKET_CLOSE:
			printf(STR(TK_SQUARE_BRACKET_CLOSE));
			break;
		case TK_ALT_(TK_SQUARE_BRACKET_CLOSE):
			printf(STR(ALT + TK_SQUARE_BRACKET_CLOSE));
			break;
		case TK_CARET:
			printf(STR(TK_CARET));
			break;
		case TK_ALT_(TK_CARET):
			printf(STR(ALT + TK_CARET));
			break;
		case TK_UNDERSCORE:
			printf(STR(TK_UNDERSCORE));
			break;
		case TK_ALT_(TK_UNDERSCORE):
			printf(STR(ALT + TK_UNDERSCORE));
			break;
		case TK_GRAVE_ACCENT:
			printf(STR(TK_GRAVE_ACCENT));
			break;
		case TK_ALT_(TK_GRAVE_ACCENT):
			printf(STR(ALT + TK_GRAVE_ACCENT));
			break;
		case TK_a:
			printf(STR(TK_a));
			break;
		case TK_ALT_(TK_a):
			printf(STR(ALT + TK_a));
			break;
		case TK_b:
			printf(STR(TK_b));
			break;
		case TK_ALT_(TK_b):
			printf(STR(ALT + TK_b));
			break;
		case TK_c:
			printf(STR(TK_c));
			break;
		case TK_ALT_(TK_c):
			printf(STR(ALT + TK_c));
			break;
		case TK_d:
			printf(STR(TK_d));
			break;
		case TK_ALT_(TK_d):
			printf(STR(ALT + TK_d));
			break;
		case TK_e:
			printf(STR(TK_e));
			break;
		case TK_ALT_(TK_e):
			printf(STR(ALT + TK_e));
			break;
		case TK_f:
			printf(STR(TK_f));
			break;
		case TK_ALT_(TK_f):
			printf(STR(ALT + TK_f));
			break;
		case TK_g:
			printf(STR(TK_g));
			break;
		case TK_ALT_(TK_g):
			printf(STR(ALT + TK_g));
			break;
		case TK_h:
			printf(STR(TK_h));
			break;
		case TK_ALT_(TK_h):
			printf(STR(ALT + TK_h));
			break;
		case TK_i:
			printf(STR(TK_i));
			break;
		case TK_ALT_(TK_i):
			printf(STR(ALT + TK_i));
			break;
		case TK_j:
			printf(STR(TK_j));
			break;
		case TK_ALT_(TK_j):
			printf(STR(ALT + TK_j));
			break;
		case TK_k:
			printf(STR(TK_k));
			break;
		case TK_ALT_(TK_k):
			printf(STR(ALT + TK_k));
			break;
		case TK_l:
			printf(STR(TK_l));
			break;
		case TK_ALT_(TK_l):
			printf(STR(ALT + TK_l));
			break;
		case TK_m:
			printf(STR(TK_m));
			break;
		case TK_ALT_(TK_m):
			printf(STR(ALT + TK_m));
			break;
		case TK_n:
			printf(STR(TK_n));
			break;
		case TK_ALT_(TK_n):
			printf(STR(ALT + TK_n));
			break;
		case TK_o:
			printf(STR(TK_o));
			break;
		case TK_ALT_(TK_o):
			printf(STR(ALT + TK_o));
			break;
		case TK_p:
			printf(STR(TK_p));
			break;
		case TK_ALT_(TK_p):
			printf(STR(ALT + TK_p));
			break;
		case TK_q:
			printf(STR(TK_q));
			break;
		case TK_ALT_(TK_q):
			printf(STR(ALT + TK_q));
			break;
		case TK_r:
			printf(STR(TK_r));
			break;
		case TK_ALT_(TK_r):
			printf(STR(ALT + TK_r));
			break;
		case TK_s:
			printf(STR(TK_s));
			break;
		case TK_ALT_(TK_s):
			printf(STR(ALT + TK_s));
			break;
		case TK_t:
			printf(STR(TK_t));
			break;
		case TK_ALT_(TK_t):
			printf(STR(ALT + TK_t));
			break;
		case TK_u:
			printf(STR(TK_u));
			break;
		case TK_ALT_(TK_u):
			printf(STR(ALT + TK_u));
			break;
		case TK_v:
			printf(STR(TK_v));
			break;
		case TK_ALT_(TK_v):
			printf(STR(ALT + TK_v));
			break;
		case TK_w:
			printf(STR(TK_w));
			break;
		case TK_ALT_(TK_w):
			printf(STR(ALT + TK_w));
			break;
		case TK_x:
			printf(STR(TK_x));
			break;
		case TK_ALT_(TK_x):
			printf(STR(ALT + TK_x));
			break;
		case TK_y:
			printf(STR(TK_y));
			break;
		case TK_ALT_(TK_y):
			printf(STR(ALT + TK_y));
			break;
		case TK_z:
			printf(STR(TK_z));
			break;
		case TK_ALT_(TK_z):
			printf(STR(ALT + TK_z));
			break;
		case TK_CURLY_BRACKET_OPEN:
			printf(STR(TK_CURLY_BRACKET_OPEN));
			break;
		case TK_ALT_(TK_CURLY_BRACKET_OPEN):
			printf(STR(ALT + TK_CURLY_BRACKET_OPEN));
			break;
		case TK_PIPE:
			printf(STR(TK_PIPE));
			break;
		case TK_ALT_(TK_PIPE):
			printf(STR(ALT + TK_PIPE));
			break;
		case TK_CURLY_BRACKET_CLOSE:
			printf(STR(TK_CURLY_BRACKET_CLOSE));
			break;
		case TK_ALT_(TK_CURLY_BRACKET_CLOSE):
			printf(STR(ALT + TK_CURLY_BRACKET_CLOSE));
			break;
		case TK_TILDE:
			printf(STR(TK_TILDE));
			break;
		case TK_ALT_(TK_TILDE):
			printf(STR(ALT + TK_TILDE));
			break;
		case TK_BACKSPACE:
			printf(STR(TK_BACKSPACE));
			break;
		case TK_ALT_(TK_BACKSPACE):
			printf(STR(ALT + TK_BACKSPACE));
			break;
		case TK_F1:
			printf(STR(TK_F1));
			break;
		case TK_ALT_(TK_F1):
			printf(STR(ALT + TK_F1));
			break;
		case TK_F2:
			printf(STR(TK_F2));
			break;
		case TK_ALT_(TK_F2):
			printf(STR(ALT + TK_F2));
			break;
		case TK_F3:
			printf(STR(TK_F3));
			break;
		case TK_ALT_(TK_F3):
			printf(STR(ALT + TK_F3));
			break;
		case TK_F4:
			printf(STR(TK_F4));
			break;
		case TK_ALT_(TK_F4):
			printf(STR(ALT + TK_F4));
			break;
		case TK_F5:
			printf(STR(TK_F5));
			break;
		case TK_ALT_(TK_F5):
			printf(STR(ALT + TK_F5));
			break;
		case TK_F6:
			printf(STR(TK_F6));
			break;
		case TK_ALT_(TK_F6):
			printf(STR(ALT + TK_F6));
			break;
		case TK_F7:
			printf(STR(TK_F7));
			break;
		case TK_ALT_(TK_F7):
			printf(STR(ALT + TK_F7));
			break;
		case TK_F8:
			printf(STR(TK_F8));
			break;
		case TK_ALT_(TK_F8):
			printf(STR(ALT + TK_F8));
			break;
		case TK_F9:
			printf(STR(TK_F9));
			break;
		case TK_ALT_(TK_F9):
			printf(STR(ALT + TK_F9));
			break;
		case TK_F10:
			printf(STR(TK_F10));
			break;
		case TK_ALT_(TK_F10):
			printf(STR(ALT + TK_F10));
			break;
		case TK_F11:
			printf(STR(TK_F11));
			break;
		case TK_ALT_(TK_F11):
			printf(STR(ALT + TK_F11));
			break;
		case TK_F12:
			printf(STR(TK_F12));
			break;
		case TK_ALT_(TK_F12):
			printf(STR(ALT + TK_F12));
			break;
		case TK_UP:
			printf(STR(TK_UP));
			break;
		case TK_ALT_(TK_UP):
			printf(STR(ALT + TK_UP));
			break;
		case TK_DOWN:
			printf(STR(TK_DOWN));
			break;
		case TK_ALT_(TK_DOWN):
			printf(STR(ALT + TK_DOWN));
			break;
		case TK_RIGHT:
			printf(STR(TK_RIGHT));
			break;
		case TK_ALT_(TK_RIGHT):
			printf(STR(ALT + TK_RIGHT));
			break;
		case TK_LEFT:
			printf(STR(TK_LEFT));
			break;
		case TK_ALT_(TK_LEFT):
			printf(STR(ALT + TK_LEFT));
			break;
		case TK_HOME:
			printf(STR(TK_HOME));
			break;
		case TK_ALT_(TK_HOME):
			printf(STR(ALT + TK_HOME));
			break;
		case TK_INSERT:
			printf(STR(TK_INSERT));
			break;
		case TK_ALT_(TK_INSERT):
			printf(STR(ALT + TK_INSERT));
			break;
		case TK_DELETE:
			printf(STR(TK_DELETE));
			break;
		case TK_ALT_(TK_DELETE):
			printf(STR(ALT + TK_DELETE));
			break;
		case TK_END:
			printf(STR(TK_END));
			break;
		case TK_ALT_(TK_END):
			printf(STR(ALT + TK_END));
			break;
		case TK_PAGE_DOWN:
			printf(STR(TK_PAGE_DOWN));
			break;
		case TK_ALT_(TK_PAGE_DOWN):
			printf(STR(ALT + TK_PAGE_DOWN));
			break;
		case TK_PAGE_UP:
			printf(STR(TK_PAGE_UP));
			break;
		case TK_ALT_(TK_PAGE_UP):
			printf(STR(ALT + TK_PAGE_UP));
			break;
		case TK_CTRL_UP:
			printf(STR(TK_CTRL_UP));
			break;
		case TK_ALT_(TK_CTRL_UP):
			printf(STR(ALT + TK_CTRL_UP));
			break;
		case TK_CTRL_DOWN:
			printf(STR(TK_CTRL_DOWN));
			break;
		case TK_ALT_(TK_CTRL_DOWN):
			printf(STR(ALT + TK_CTRL_DOWN));
			break;
		case TK_CTRL_RIGHT:
			printf(STR(TK_CTRL_RIGHT));
			break;
		case TK_ALT_(TK_CTRL_RIGHT):
			printf(STR(ALT + TK_CTRL_RIGHT));
			break;
		case TK_CTRL_LEFT:
			printf(STR(TK_CTRL_LEFT));
			break;
		case TK_ALT_(TK_CTRL_LEFT):
			printf(STR(ALT + TK_CTRL_LEFT));
			break;
	}
}

void texit(tkey_t k, void* p)
{
	tk_finish();
}

int main()
{
	tk_init();
	tk_bind_key(TK_ALT_(TK_CTRL_E), texit, NULL);
	tk_bind_all_key(fbind, NULL);

	tk_wait();

	return 0;
}
