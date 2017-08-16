/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_getplots2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:31:50 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/15 15:59:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_shiftx(t_plot *plot_head, int shift)
{
	t_plot	*tmp;

	tmp = plot_head;
	while (tmp)
	{
		tmp->x1 += shift;
		tmp->x2 += shift;
		tmp = tmp->next;
	}
}

void	plot_shifty(t_plot *plot_head, int shift)
{
	t_plot	*tmp;

	tmp = plot_head;
	while (tmp)
	{
		tmp->y1 += shift;
		tmp->y2 += shift;
		tmp = tmp->next;
	}
}

void	wf_putplots(t_param *params)
{
	t_plot	*tmp;
	t_plot	*clear;

	tmp = params->plot_head;
	while (tmp)
	{
		bresenham(tmp, params);
		tmp = tmp->next;
	}
	tmp = params->plot_head;
	while (tmp)
	{
		clear = tmp;
		tmp = tmp->next;
		free(clear);
	}
	params->plot_head = NULL;
	ft_freezero(params->max, sizeof(t_max));
	params->max = (t_max *)ft_memalloc(sizeof(t_max));
	image_put(params);
	wf_print_legend(params, "text/legend1.txt", 0);
	wf_print_legend(params, "text/legend2.txt", 1);
}
