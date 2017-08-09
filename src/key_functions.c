/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 03:39:06 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/08 23:34:16 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void color_swap(int keycode, t_param *params)
{
	if (keycode == ONE)
		get_color_scheme(params, 0);
	if (keycode == TWO)
		get_color_scheme(params, 1);
	if (keycode == THREE)
		get_color_scheme(params, 2);
	if (keycode == FOUR)
		get_color_scheme(params, 3);
	if (keycode == FIVE)
		get_color_scheme(params, 4);
	if (keycode == SIX)
		get_color_scheme(params, 5);
	if (keycode == SEVEN)
		get_color_scheme(params, 6);
	if (keycode == EIGHT)
		get_color_scheme(params, 7);
	if (keycode == NINE)
		get_color_scheme(params, 8);
}

void translate(int keycode, t_param *params)
{
	int x;

	x = params->grid_size;
	if (keycode == A || keycode == D)
		params->startx += (keycode == A) ? -1 * x : x;
	else
		params->starty += (keycode == W) ? -1 * x : x;
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
		wf_get_plot_map(params);
	}
	if (keycode == RSHIFT || keycode == RCNTRL)
	{
		GAMMA += (keycode == RSHIFT ? DEG : -1 * DEG);
		mlx_clear_window(params->mlx, params->win);
		wf_get_plot_map(params);
	}
	if ((A <= keycode && keycode <= D) || keycode == W)
	{
		translate(keycode, params);
		mlx_clear_window(params->mlx, params->win);
		wf_get_plot_map(params);
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
		wf_get_plot_map(params);
	}
	if (keycode == RBRACK || keycode == LBRACK)
	{
		params->grid_size += (keycode == RBRACK ? 1 : -1);
		mlx_clear_window(params->mlx, params->win);
		wf_get_plot_map(params);
	}
	if (keycode == ZERO)
	{
		ALPHA = 0;
		BETA = 0;
		GAMMA = 0;
		mlx_clear_window(params->mlx, params->win);
		wf_get_plot_map(params);
	}
	if (ONE <= keycode && keycode <= EIGHT && keycode != PLUS && keycode != MINUS)
	{
		color_swap(keycode, params);
		mlx_clear_window(params->mlx, params->win);
		wf_get_plot_map(params);
	}
	if (keycode == ESC)
		memdel_and_exit(params);
	printf("% 3f % 3f % 3f\n", ALPHA, BETA, GAMMA);
	return (1);
}
