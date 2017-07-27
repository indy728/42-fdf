/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_2d_plot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:14:50 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/26 21:46:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getx(int x, int y, int z, t_param *params)
{
	int	g;

	y *= 1;
	g = params->grid_size;
	z *= params->height;
	y = y * g;
	x = x * g;
	x = cos(BETA) * cos(GAMMA) * x -
		cos(BETA) * sin(GAMMA) * y +
		sin(BETA) * z;
	return (x);
}

int	gety(int x, int y, int z, t_param *params)
{
	int	g;

	g = params->grid_size;
	z *= params->height;
	x = x * g;
	y = y * g;
	y = (sin(ALPHA) * sin(BETA) * cos(GAMMA) + cos(BETA) * sin(GAMMA)) * x +
		(cos(ALPHA) * cos(GAMMA) - sin(ALPHA) * sin(BETA) * sin(GAMMA)) * (y) -
		sin(ALPHA) * cos(BETA) * z;
	return (y);
}
