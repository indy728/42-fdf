/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 03:39:06 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/14 19:00:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	color_swap(int keycode, t_param *params)
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

static void	translate(int keycode, t_param *params)
{
	int x;

	x = params->grid_size;
	if (keycode == LEFT || keycode == RIGHT)
		params->startx += (keycode == LEFT) ? -1 * x : x;
	else
		params->starty += (keycode == UP) ? -1 * x : x;
}

int			my_key_funct(int keycode, t_param *params)
{
	if (keycode == COMMA || keycode == ELL)
		params->beta += (keycode == ELL ? DEG : -1 * DEG);
	if (keycode == POINT || keycode == SEMI)
		params->alpha += (keycode == POINT ? DEG : -1 * DEG);
	if (keycode == SLASH || keycode == APOS)
		GAMMA += (keycode == SLASH ? DEG : -1 * DEG);
	if (LEFT <= keycode && keycode <= UP)
		translate(keycode, params);
	if (keycode == PLUS || keycode == MINUS)
		params->height += (keycode == PLUS ? 1 : -1);
	if (keycode == RBRACK || keycode == LBRACK)
		params->grid_size += (keycode == RBRACK ? 1 : -1);
	if (keycode == NP_CLEAR || keycode == NP_SEVEN)
		color_shift(keycode, &params->rgb->rmax);
	if (keycode == NP_ONE || keycode == NP_FOUR)
		color_shift(keycode, &params->rgb->rmin);	
	if (keycode == NP_EQUALS || keycode == NP_EIGHT)
		color_shift(keycode, &params->rgb->gmax);
	if (keycode == NP_FIVE || keycode == NP_TWO)
		color_shift(keycode, &params->rgb->gmin);	
	if (keycode == NP_SLASH || keycode == NP_NINE)
		color_shift(keycode, &params->rgb->bmax);
	if (keycode == NP_SIX || keycode == NP_THREE)
		color_shift(keycode, &params->rgb->bmin);	
	if (keycode == ZERO)
	{
		ALPHA = 0;
		BETA = 0;
		GAMMA = 0;
	}
	if (ONE <= keycode && keycode <= EIGHT &&
			keycode != PLUS && keycode != MINUS)
		color_swap(keycode, params);
	if (keycode == ESC)
		memdel_and_exit(params);
	/*if (keycode == C)
	{
		ft_putstr("clearing window\n");
		mlx_clear_window(params->mlx, params->win);
		return (1);
	}*/
//	printf("%d\n", keycode);
	mlx_clear_window(params->mlx, params->win);
	wf_get_plot_map(params);
//	printf("% 3f % 3f % 3f\n", ALPHA, BETA, GAMMA);
	return (1);
}
