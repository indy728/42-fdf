#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define GRID 30
# define HEIGHT 3
# define STARTX 500
# define STARTY 500

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	int			grid_size;
	int			startx;
	int			starty;
	t_list		*map;
	double		alpha;
	double		beta;
	int			height;
}				t_param;
/*
typedef struct			s_plot_list
{
	int					*arr;
	int					size;
	struct s_plot_list	*next;
}						t_plot_list;
*/
typedef enum	e_keys
{
	A, S, D, F, H1, G, ZED, X, C, V, B = 11, Q, W, E, R, Y, T,
	ONE, TWO, THREE, FOUR, SIX, FIVE, PLUS, NINE, SEVEN, MINUS, EIGHT, ZERO,
	RBRACK, O, U, LBRACK, I, P, RETURN, ELL, JAY, APOS, K, SEMI, BACKSLASH, COMMA,
	SLASH, N, M, POINT, TAB, SPACE, TILDE, DEL, ESC = 53,
	LEFT = 123, RIGHT, DOWN, UP,
	LCNTRL = 256, LSHIFT, RSHIFT, LCMD, RCMD, LOPT, ROPT, RCNTRL = 269
}				t_keys;

int		getx(int x, int z, t_param *params);
int		gety(int x, int y, int z, t_param *params);
void	wf_draw_linex(t_param *param, int row, int col);
void	wf_draw_liney(t_param *param, int row, int col);

#endif
