/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_bresenham_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:55:25 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/08 20:32:53 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*t_bres	*wf_bresenham_init(t_plot *plots, t_param *params)
{
	t_bres	*new;

	new->xshift = 650 - (params->max->xmax - params->max->xmin) / 2;
	new->yshift = 650 - (params->max->ymax - params->max->ymin) / 2;
}*/

void	bres_rgb_init(t_bres *bres, t_param *params, t_plot *plots)
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


t_bres	*tbres_init(t_param *params, t_plot *plots)
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
