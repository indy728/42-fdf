/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_bresenham_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:55:25 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/09 01:43:18 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_drgb_and_steps(int dif, t_bres *bres)
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

void		color_step(int dif, t_bres *bres)
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

static void	bres_rgb_init(t_bres *bres, t_param *params, t_plot *plots)
{
	t_rgb	*rgb;
	t_max	*max;

	rgb = params->rgb;
	max = params->max;
	bres->r1 = rgb->rmin + (plots->z1 - max->zmin) * (rgb->rmax - rgb->rmin)
		/ (ft_max(1, max->zmax - max->zmin));
	bres->r2 = rgb->rmin + (plots->z2 - max->zmin) * (rgb->rmax - rgb->rmin)
		/ (ft_max(1, max->zmax - max->zmin));
	bres->g1 = rgb->gmin + (plots->z1 - max->zmin) * (rgb->gmax - rgb->gmin)
		/ (ft_max(1, max->zmax - max->zmin));
	bres->g2 = rgb->gmin + (plots->z2 - max->zmin) * (rgb->gmax - rgb->gmin)
		/ (ft_max(1, max->zmax - max->zmin));
	bres->b1 = rgb->bmin + (plots->z1 - max->zmin) * (rgb->bmax - rgb->bmin)
		/ (ft_max(1, max->zmax - max->zmin));
	bres->b2 = rgb->bmin + (plots->z2 - max->zmin) * (rgb->bmax - rgb->bmin)
		/ (ft_max(1, max->zmax - max->zmin));
}

t_bres		*tbres_init(t_param *params, t_plot *plots)
{
	t_bres	*bres;

	bres = ft_memalloc(sizeof(t_bres));
	ft_bzero(bres, sizeof(t_bres));
	bres_rgb_init(bres, params, plots);
	bres->xstep = (plots->x1 > plots->x2) ? -1 : 1;
	bres->ystep = (plots->y1 > plots->y2) ? -1 : 1;
	bres->dx = ft_abs(plots->x1 - plots->x2);
	bres->dy = ft_abs(plots->y1 - plots->y2);
	bres->dr = ft_abs(bres->r2 - bres->r1);
	bres->dg = ft_abs(bres->g2 - bres->g1);
	bres->db = ft_abs(bres->b2 - bres->b1);
	if (bres->dr == 0)
		bres->rstep = 0;
	else
		bres->rstep = bres->r2 < bres->r1 ? -1 : 1;
	if (bres->dg == 0)
		bres->gstep = 0;
	else
		bres->gstep = bres->g2 < bres->g1 ? -1 : 1;
	if (bres->db == 0)
		bres->bstep = 0;
	else
		bres->bstep = bres->b2 < bres->b1 ? -1 : 1;
	return (bres);
}
