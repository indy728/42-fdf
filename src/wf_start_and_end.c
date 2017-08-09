/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_start_and_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 19:52:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/09 00:37:46 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	memdel_and_exit(t_param *params)
{
		ft_putstr("ESC: Ending program.\n");
		mlx_destroy_window(params->mlx, params->win);
		ft_lstdel(&params->map, ft_freezero);
		free(params->rgb);
		free(params);
		exit (0);
}

void	colormin_init(t_param *params)
{
	params->colormin[0] = 0;
	params->colormin[1] = 0xff;
	params->colormin[2] = 0xff00;
	params->colormin[3] = 0xff0000;
	params->colormin[4] = 0x381904; // brown
	params->colormin[5] = 0xff0000;
	params->colormin[6] = 0x4b0082;
	params->colormin[7] = 0x08e8de; // turquoise
	params->colormin[8] = 0x778899; // light slate
}

void	colormax_init(t_param *params)
{
	params->colormax[0] = 0xffffff;
	params->colormax[1] = 0xffa500; // orange
	params->colormax[2] = 0x800080; // purple
	params->colormax[3] = 0xffd700; // gold
	params->colormax[4] = 0xffffff;
	params->colormax[5] = 0xff;
	params->colormax[6] = 0xffff00; // yellow
	params->colormax[7] = 0xff69b4; // hot pink
	params->colormax[8] = 0xc0c0c0; // silver
}

void	get_color_scheme(t_param *params, int i)
{
	t_rgb	*colors;

	colors = ft_memalloc(sizeof(t_rgb));
	colors->rmax = get_rgb_r(params->colormax[i]);
	colors->gmax = get_rgb_g(params->colormax[i]);
	colors->bmax = get_rgb_b(params->colormax[i]);
	colors->rmin = get_rgb_r(params->colormin[i]);
	colors->gmin = get_rgb_g(params->colormin[i]);
	colors->bmin = get_rgb_b(params->colormin[i]);
	params->rgb = colors;
}

void	get_grid_start_size(t_param *params)
{
	int x;
	int i;
	t_list	*scout;

	i = 0;
	x = params->map->content_size / sizeof(int);
	scout = params->map;
	while (scout)
	{
		scout = scout->next;
		i++;
	}
	ft_printf("x = %d, y = %d\n", x, i);
	params->grid_size = 1100 / (int)sqrt(x * x + i * i);
}

t_param	*param_init(t_list *begin_list, char *title)
{
	t_param	*params;

	params = (t_param *)malloc(sizeof(t_param));
	ft_bzero(params, sizeof(t_param));
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, 1300, 1300, title);
	params->startx = 650;
	params->starty = 650;
	params->plot_head = NULL;
	params->max = NULL;
	params->alpha = -.698132;
	params->beta = 0;
	params->gamma = 0.610865;
	params->map = begin_list;
	get_grid_start_size(params);
	params->height = 1;
	colormin_init(params);
	colormax_init(params);
	get_color_scheme(params, 0);
	return (params);
}
