/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_draw_linex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 02:45:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/19 00:15:15 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void putsqr(void *mlx, void *win, int x, int y, int color)
{
	int i = 0;
	int j;
	int size = 2;

	while (i < size)
	{
		j = 0;
		while (j < size)
			mlx_pixel_put(mlx, win, (x - size / 2) + j++, (y - size / 2) + i, color);
		++i;
	}
}

void	bresenham(int x1, int x2, int y1, int y2, t_param *params)
{
	int	dy;
	int	dx;
	int e;
	int xstep;
	int ystep;

	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	e = 2 * (dy - dx);
	ystep = (y1 > y2) ? -1 : 1;
	xstep = (x1 > x2) ? -1 : 1;
	putsqr(params->mlx, params->win, x1, y1, 0x00FF0000);
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
	mlx_pixel_put(params->mlx, params->win, x1, y1, 0x00FFFFFF);
	}
}

void	wf_draw_linex(t_param *params, int row, int col)
{
	int *arr;
	int n = 0;
	t_list *scout;

	scout = params->map;
	while (n++ < row)
		scout = scout->next;
	arr = scout->content;
	bresenham(getx(col, arr[col], params),
			getx(col + 1, arr[col + 1], params),
			gety(col, row, arr[col], params),
			gety(col + 1, row, arr[col + 1], params), params);
}
