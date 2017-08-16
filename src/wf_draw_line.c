/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 02:45:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/15 01:09:12 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	wf_pixel_put(t_param *params, t_plot *plots, t_bres *bres)
{
	int		shiftx;
	int		shifty;
	static int i;

	shiftx = params->startx - (params->max->xmax - params->max->xmin) / 2;
	shifty = params->starty - (params->max->ymax - params->max->ymin) / 2;
	if (100 <= plots->x1 + shiftx && plots->x1 + shiftx <= 1200 &&
			100 <= plots->y1 + shifty && plots->y1 + shifty <= 1200)
		img_pixel_put(params->img, plots->x1 + shiftx, 
				plots->y1 + shifty, get_pixel_color(bres));
}

static void	bres_dx(t_param *params, t_plot *plots, t_bres *bres)
{
	int		e;

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

static void	bres_dy(t_param *params, t_plot *plots, t_bres *bres)
{
	int		e;

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

void		bresenham(t_plot *plots, t_param *params)
{
	t_bres	*bres;

	bres = tbres_init(params, plots);
	wf_pixel_put(params, plots, bres);
	if (bres->dy > bres->dx)
		bres_dy(params, plots, bres);
	else
		bres_dx(params, plots, bres);
	free(bres);
}
