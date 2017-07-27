/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:43:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/26 20:20:16 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define GRID 30
# define HEIGHT 3

# define ALPHA params->alpha
# define BETA params->beta
# define GAMMA params->gamma
# define DEG (M_PI / 180 * 5)
# define INV_FILE "unable to read file"
# define ARRAY "input map does not exist or is not valid"
# define KMDB(x) ft_printf("HERE %d\n", x);

typedef struct	s_plot
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			z1;
	int			z2;
	struct s_plot	*next;
}				t_plot;

typedef struct	s_max
{
	int			xmax;
	int			xmin;
	int			ymax;
	int			ymin;
}				t_max;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	int			grid_size;
	int			height;
	double		alpha;
	double		beta;
	double		gamma;
	t_plot		*plot_head;
	t_max		*max;
	t_list		*map;
}				t_param;

typedef enum	e_keys
{
	A, S, D, F, H1, G, ZED, X, C, V, B = 11, Q, W, E, R, Y, T,
	ONE, TWO, THREE, FOUR, SIX, FIVE, PLUS, NINE, SEVEN, MINUS, EIGHT, ZERO,
	RBRACK, O, U, LBRACK, I, P, RETURN, ELL, JAY, APOS, K, SEMI,
	BACKSLASH, COMMA, SLASH, N, M, POINT, TAB, SPACE, TILDE, DEL, ESC = 53,
	LEFT = 123, RIGHT, DOWN, UP,
	LCNTRL = 256, LSHIFT, RSHIFT, LCMD, RCMD, LOPT, ROPT, RCNTRL = 269
}				t_keys;

int				getx(int x, int y, int z, t_param *params);
int				gety(int x, int y, int z, t_param *params);
t_plot			*get_plots(t_param *param, int row, int col, char axis);
int				my_key_funct(int keycode, t_param *params);
void			wf_plotcat(t_plot **head, t_plot *new);
void			wf_delplots(t_plot **head);
t_max			*wf_getmax(t_plot *head);
void			bresenham(int x1, int x2, int y1, int y2, t_param *params);
void			wf_putplots(t_param *params);
void			put_to_screen(t_param *params);
t_param			*param_init(t_list *begin_list, char *str);
void			memdel_and_exit(t_param *params);

#endif
