/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:43:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/10 01:04:21 by kmurray          ###   ########.fr       */
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

# define DR bres->dr
# define DG bres->dg
# define DB bres->db
# define RE bres->re
# define GE bres->ge
# define BE bres->be

typedef struct		s_plot
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	struct s_plot	*next;
}					t_plot;

typedef struct	s_max
{
	int			xmax;
	int			xmin;
	int			ymax;
	int			ymin;
	int			zmax;
	int			zmin;
}				t_max;

typedef struct	s_rgb
{
	int			rmax;
	int			rmin;
	int			gmax;
	int			gmin;
	int			bmax;
	int			bmin;
}				t_rgb;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	int			startx;
	int			starty;
	int			grid_size;
	int			height;
	double		alpha;
	double		beta;
	double		gamma;
	int			colormin[9];
	int			colormax[9];
	t_rgb		*rgb;
	t_plot		*plot_head;
	t_max		*max;
	t_list		*map;
}				t_param;

typedef struct	s_bres
{
	int			r1;
	int			r2;
	int			g1;
	int			g2;
	int			b1;
	int			b2;
	int			ystep;
	int			xstep;
	int			rstep;
	int			rjump;
	int			gstep;
	int			gjump;
	int			bstep;
	int			bjump;
	int			re;
	int			ge;
	int			be;
	int			dx;
	int			dy;
	int			dr;
	int			dg;
	int			db;
}				t_bres;

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
int				my_key_funct(int keycode, t_param *params);
void			wf_plotcat(t_plot **head, t_plot *new);
t_max			*wf_getmax(t_plot *head);
void			bresenham(t_plot *plots, t_param *params);

t_param			*param_init(t_list *begin_list, int ac, char **av);
void			memdel_and_exit(t_param *params, int i);
int				get_rgb_r(int color);
int				get_rgb_g(int color);
int				get_rgb_b(int color);
int				get_pixel_color(t_bres *bres);
void			get_color_scheme(t_param *params, int i);

void			wf_putplots(t_param *params);
void			wf_get_plot_map(t_param *params);
t_plot			*wf_get_2d_plots(t_param *param, int row, int col, char axis);
void			plot_shiftx(t_plot *plot_head, int shift);
void			plot_shifty(t_plot *plot_head, int shift);

t_bres			*tbres_init(t_param *params, t_plot *plots);
void			set_drgb_and_steps(int dif, t_bres *bres);
void			color_step(int dif, t_bres *bres);

#endif
