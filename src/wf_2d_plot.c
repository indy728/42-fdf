/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_2d_plot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 20:14:50 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/15 19:18:01 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Instead of coding a matrix-multiplying function, I just did the generic
**	matrix multiplication on paper and coded in the final algorithm to plot
**	3D coordinates in 2D with 3 rotational axes. Z valuation is based on 10%
**	of grid size, using a lazy way to ensure integer integrity is maintained.
*/

int	getx(int x, int y, int z, t_param *params)
{
	int	g;

	g = params->grid_size;
	z *= params->grid_size * 10000 / 100000 * params->height;
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
	z *= params->grid_size * 10000 / 100000 * params->height;
	x = x * g;
	y = y * g;
	y = (sin(ALPHA) * sin(BETA) * cos(GAMMA) + cos(BETA) * sin(GAMMA)) * x +
		(cos(ALPHA) * cos(GAMMA) - sin(ALPHA) * sin(BETA) * sin(GAMMA)) * (y) +
		sin(ALPHA) * cos(BETA) * z;
	return (y);
}
