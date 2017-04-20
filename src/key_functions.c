/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 03:39:06 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/20 04:16:33 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_to_screen(t_param *params)
{
	int i;
	int row = 0;
	t_list	*scout;

	scout = params->map;
	while (scout->next)
	{
		i = 0;
		while (i + 1 < scout->content_size / sizeof(int))
		{
			wf_draw_line(params, row, i, 'x');
			wf_draw_line(params, row, i, 'y');
			++i;
		}
		wf_draw_line(params, row, i, 'y');
		scout = scout->next;
		++row;
	}
	i = 0;
	while (i + 1 < scout->content_size / sizeof(int))
	{
		wf_draw_line(params, row, i, 'x');
		++i;
	}
}

int	my_key_funct(int keycode, t_param *params)
{
	void	*tmp;

	if (LEFT <= keycode && keycode <= UP)
	{
		if (keycode < DOWN)
			params->beta += (keycode == LEFT ? .02 : -.02);
		else
			params->alpha += (keycode == UP ? .02 : -.02);
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
	{
		ft_putstr("ESC: Ending program.\n");
		mlx_destroy_window(params->mlx, params->win);
		ft_lstdel(&params->map, ft_freezero);
		free (params);
		exit (0);
	}
	return (1);
}
