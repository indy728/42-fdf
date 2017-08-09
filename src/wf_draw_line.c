/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 02:45:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/08 23:30:04 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_drgb_and_steps(int dif, t_bres *bres)
{
	while (DR > dif && dif != 0)
	{
		++bres->rjump;
		DR -= dif;
	}
	while (DG > dif & dif != 0)
	{
		++bres->gjump;
		DG -= dif;
	}
	while (DB > dif & dif != 0)
	{
		++bres->bjump;
		DB -= dif;
	}
}

void	color_step(int dif, t_bres *bres)
{
	if (RE < 0)
		RE += DR;
	else
	{
		RE -= dif - DR;
		bres->r1 += bres->rstep;
	}
	if (GE < 0)
		GE += DG;
	else
	{
		GE -= dif - DG;
		bres->g1 += bres->gstep;
	}
	if (BE < 0)
		BE += DB;
	else
	{
		BE -= dif - DB;
		bres->b1 += bres->bstep;
	}
	bres->r1 += bres->rjump * bres->rstep;
	bres->g1 += bres->gjump * bres->gstep;
	bres->b1 += bres->bjump * bres->bstep;
}

void	wf_pixel_put(t_param *params, t_plot *plots, t_bres *bres)
{
	int		shiftx;
	int		shifty;

	shiftx = params->startx - (params->max->xmax - params->max->xmin) / 2;
	shifty = params->starty - (params->max->ymax - params->max->ymin) / 2;
	if (100 <= plots->x1 + shiftx && plots->x1 + shiftx <= 1200 &&
			100 <= plots->y1 + shifty && plots->y1 + shifty <= 1200)
		mlx_pixel_put(params->mlx, params->win,
				plots->x1 + shiftx,
				plots->y1 + shifty, get_pixel_color(bres));
}

void	bresenham(t_plot *plots, t_param *params)
{
	t_bres	*bres;
	int		e;

	bres = tbres_init(params, plots);
	wf_pixel_put(params, plots, bres);
	if (bres->dy > bres->dx)
	{
		e = 2 * bres->dx - bres->dy;
		set_drgb_and_steps(bres->dy, bres);
		while (plots->x1 != plots->x2 || plots->y1 != plots->y2)
		{
			plots->y1 += (plots->y1 == plots->y2) ? 0 : bres->ystep;
			if (e < 0)
				e += 2 * bres->dx;
			else
			{
				plots->x1 += bres->xstep;
				e -= 2 * (bres->dy - bres->dx);
			}
			color_step(bres->dy, bres);
			wf_pixel_put(params, plots, bres);
		}
	}
	else
	{
		e = 2 * bres->dy - bres->dx;
		set_drgb_and_steps(bres->dx, bres);
		while (plots->x1 != plots->x2 || plots->y1 != plots->y2)
		{
			plots->x1 += (plots->x1 == plots->x2) ? 0 : bres->xstep;
			if (e < 0)
				e += 2 * bres->dy;
			else
			{
				plots->y1 += bres->ystep;
				e += 2 * (bres->dy - bres->dx);
			}
			color_step(bres->dx, bres);
			wf_pixel_put(params, plots, bres);
		}
	}
	free(bres);
}
