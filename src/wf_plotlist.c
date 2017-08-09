/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_plotlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:31:50 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/08 23:31:30 by kmurray          ###   ########.fr       */
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

void	wf_plotcat(t_plot **head, t_plot *new)
{
	t_plot	*tmp;

	tmp = *head;
	if (!tmp)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_max	*wf_getmax(t_plot *head)
{
	t_max	*max;
	t_plot	*tmp;
	
	max = ft_memalloc(sizeof(t_max));
	ft_bzero(max, sizeof(t_max));
	tmp = head;
	while (tmp)
	{
		max->xmax = ft_max(max->xmax, tmp->x1);
		max->xmin = ft_min(max->xmin, tmp->x1);
		max->ymax = ft_max(max->ymax, tmp->y1);
		max->ymin = ft_min(max->ymin, tmp->y1);
		max->zmax = ft_max(max->zmax, tmp->z1);
		max->zmin = ft_min(max->zmin, tmp->z1);
		tmp = tmp->next;
	}
	return (max);
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
}

t_plot		*wf_get_2d_plots(t_param *params, int row, int col, char axis)
{
	int *arr;
	int *arr2;
	int n = 0;
	t_list *scout;
	t_plot	*plot;

	plot = ft_memalloc(sizeof(t_plot));
	scout = params->map;
	while (n++ < row)
		scout = scout->next;
	arr = scout->content;
	plot->x1 = getx(col, row, arr[col], params);
	plot->y1 = gety(col, row, arr[col], params);
	plot->z1 = arr[col];
	if (axis == 'x')
	{
		plot->x2 = getx(col + 1, row, arr[col + 1], params);
		plot->y2 = gety(col + 1, row, arr[col + 1], params);
		plot->z2 = arr[col + 1];
	}
	else
	{
		arr2 = scout->next->content;
		plot->x2 = getx(col, row + 1, arr2[col], params);
		plot->y2 = gety(col, row + 1, arr2[col], params);
		plot->z2 = arr2[col];
	}
	return (plot);
}

void	wf_get_plot_map(t_param *params)
{
	int		i;
	int		row;
	t_list	*scout;

	row = 0;
	scout = params->map;
	KMDB(1)
	while (scout)
	{
		i = -1;
		while (++i < scout->content_size / sizeof(int))
		{
			if (i + 1 < scout->content_size / sizeof(int))
				wf_plotcat(&params->plot_head, wf_get_2d_plots(params, row, i, 'x'));
			if (scout->next)
				wf_plotcat(&params->plot_head, wf_get_2d_plots(params, row, i, 'y'));
		}
		scout = scout->next;
		++row;
	}
	KMDB(2)
	params->max = wf_getmax(params->plot_head);
	if (params->max->xmin < 0)
		plot_shiftx(params->plot_head, -1 * params->max->xmin);
	if (params->max->ymin < 0)
		plot_shifty(params->plot_head, -1 * params->max->ymin);
	wf_putplots(params);
}
