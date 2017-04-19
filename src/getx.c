/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:54:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/18 21:58:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getx(int x, int z, t_param *params)
{
	int	g;

	g = params->grid_size;
	z *= g / params->height;
	x = cos(params->beta) * (params->startx + x * g) - sin(params->beta) * z;
	return (x);
}
