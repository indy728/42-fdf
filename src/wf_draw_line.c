/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 02:45:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/14 03:49:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	wf_draw_line(void* mlx, void *win, int x1, int y1, int x2, int y2)
{
	int	dy;
	int	dx;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;
	e = dy - dx;
	if (x1 < x2)
	{
		while (x1 < x2)
		{
			mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
			if (e >= 0)
			{
				y1 += 1;
				e -= dx;
			}
			x1 += 1;
			e += dy;
		}
	}
	else
	{
		while (x1 > x2)
		{
			mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
			if (e < 0)
			{
				y1 += 1;
				e -= dx;
			}
			x1 -= 1;
			e -= dy;
		}
	}
}
