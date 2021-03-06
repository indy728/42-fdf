/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 01:09:26 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/15 19:13:25 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Simple and effective functions for isolating RGB values, playing with them,
**	and "gluing" them back together.
*/

int		get_rgb_r(int color)
{
	return ((color & 0xff0000) >> 16);
}

int		get_rgb_g(int color)
{
	return ((color & 0xff00) >> 8);
}

int		get_rgb_b(int color)
{
	return (color & 0xff);
}

int		get_pixel_color(t_bres *bres)
{
	return (bres->r1 * 0x010000 + bres->g1 * 0x0100 + bres->b1 * 0x01);
}

void	color_shift(int keycode, int *color)
{
	if (keycode == NP_CLEAR || keycode == NP_FOUR ||
			keycode == NP_EQUALS || keycode == NP_FIVE ||
			keycode == NP_SLASH || keycode == NP_SIX)
	{
		if (0xff - 0x0f < *color && *color <= 0xff)
			*color = 0;
		else
			*color += 0x0f;
	}
	else
	{
		if (*color == 0)
			*color = 0xff;
		else
			*color -= 0x0f;
	}
}
