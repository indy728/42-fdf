/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 01:09:26 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/09 02:06:45 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rgb_r(int color)
{
	return ((color & 0xff0000) >> 16);
}

int	get_rgb_g(int color)
{
	return ((color & 0xff00) >> 8);
}

int	get_rgb_b(int color)
{
	return (color & 0xff);
}

int	get_pixel_color(t_bres *bres)
{
	return (bres->r1 * 0x010000 + bres->g1 * 0x0100 + bres->b1 * 0x01);
}
