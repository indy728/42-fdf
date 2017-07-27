/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 02:45:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/26 21:59:58 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(int x1, int x2, int y1, int y2, t_param *params)
{
	int	dy;
	int	dx;
	int e;
	int xstep;
	int ystep;
	int	startx;
	int starty;

	startx = 650 - (params->max->xmax - params->max->xmin) / 2;
	starty = 650 - (params->max->ymax - params->max->ymin) / 2;
	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	ystep = (y1 > y2) ? -1 : 1;
	xstep = (x1 > x2) ? -1 : 1;
	mlx_pixel_put(params->mlx, params->win, x1 + startx, y1 + starty, 0x00FF0000);
	if (dy > dx)
	{
		e = 2 * dx - dy;
		while (x1 != x2 || y1 != y2)
		{
			xstep = (x1 == x2) ? 0 : xstep;
			ystep = (y1 == y2) ? 0 : ystep;
			y1 += ystep;
			if (e < 0)
				e += 2 * dx;
			else
			{
				x1 += xstep;
				e += 2 * (dx - dy);
			}
		mlx_pixel_put(params->mlx, params->win, x1 + startx, y1 + starty, 0x00FFFFFF);
		}
	}
	else
	{
		e = 2 * dy - dx;
		while (x1 != x2 || y1 != y2)
		{
			xstep = (x1 == x2) ? 0 : xstep;
			ystep = (y1 == y2) ? 0 : ystep;
			x1 += xstep;
			if (e < 0)
				e += 2 * dy;
			else
			{
				y1 += ystep;
				e += 2 * (dy - dx);
			}
		mlx_pixel_put(params->mlx, params->win, x1 + startx, y1 + starty, 0x00FFFFFF);
		}
	}	
}

