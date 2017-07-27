/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 03:39:06 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/26 22:21:32 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_shiftx(t_plot *plot_head, int shift)
{
	t_plot	*tmp;

	tmp = plot_head;
	while (tmp)
	{
		tmp->x1 += shift;
		tmp->x2 += shift;
		tmp = tmp->next;
	}
}

void	plot_shifty(t_plot *plot_head, int shift)
{
	t_plot	*tmp;

	tmp = plot_head;
	while (tmp)
	{
		tmp->y1 += shift;
		tmp->y2 += shift;
		tmp = tmp->next;
	}
}

void	put_to_screen(t_param *params)
{
	int		i;
	int		row;
	t_list	*scout;

	row = 0;
	scout = params->map;
	while (scout)
	{
		i = -1;
		while (++i < scout->content_size / sizeof(int))
		{
			if (i + 1 < scout->content_size / sizeof(int))
				wf_plotcat(&params->plot_head, get_plots(params, row, i, 'x'));
			if (scout->next)
				wf_plotcat(&params->plot_head, get_plots(params, row, i, 'y'));
		}
		scout = scout->next;
		++row;
	}
	params->max = wf_getmax(params->plot_head);
	if (params->max->xmin < 0)
		plot_shiftx(params->plot_head, -1 * params->max->xmin);
	if (params->max->ymin < 0)
		plot_shifty(params->plot_head, -1 * params->max->ymin);
	wf_putplots(params);
	wf_delplots(&params->plot_head);
}

int	my_key_funct(int keycode, t_param *params)
{
	if (LEFT <= keycode && keycode <= UP)
	{
		if (keycode < DOWN)
			params->beta += (keycode == LEFT ? DEG : -1 * DEG);
		else
			params->alpha += (keycode == UP ? DEG : -1 * DEG);
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == RSHIFT || keycode == RCNTRL)
	{
		GAMMA += (keycode == RSHIFT ? DEG : -1 * DEG);
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == C)
	{
		ft_putstr("clearing window\n");
		mlx_clear_window(params->mlx, params->win);
	}
	if (keycode == PLUS || keycode == MINUS)
	{
		params->height += (keycode == PLUS ? 1 : -1);
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == RBRACK || keycode == LBRACK)
	{
		params->grid_size += (keycode == RBRACK ? 1 : -1);
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == ESC)
		memdel_and_exit(params);
	ft_printf("% 3d % 3d % 3d % 3d\n", params->max->xmin, params->max->xmax, params->max->ymin, params->max->ymax);
	return (1);
}
