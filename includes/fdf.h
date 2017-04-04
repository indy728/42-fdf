#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

typedef struct	s_param
{
	void		*mlx;
	void		*win;
}				t_param;

typedef enum	e_keys
{
	A, S, D, F, H, G, Z, X, C, V, B = 11, Q, W, E, R, Y, T,
	ONE, TWO, THREE, FOUR, SIX, FIVE, EQUALS, NINE, SEVEN, MINUS, EIGHT, ZERO,
	RBRACK, O, U, LBRACK, I, P, RETURN, L, J, APOS, K, SEMI, BACKSLASH, COMMA,
	SLASH, N, M, POINT, TAB, SPACE, TILDE, DEL, ESC = 53, LCNTRL = 256,
	LSHIFT, RSHIFT, LCMD, RCMD, LOPT, ROPT, RCNTRL = 269
}				t_keys;

#endif
