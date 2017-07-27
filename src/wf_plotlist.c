/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_plotlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:31:50 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/25 15:10:49 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	wf_delplots(t_plot **head)
{
	t_plot	*tmp;
	t_plot	*clear;

	tmp = *head;
	while (tmp)
	{
		clear = tmp;
		tmp = tmp->next;
		free(clear);
	}
	*head = NULL;
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
		tmp = tmp->next;
	}
	return (max);
}

void	wf_putplots(t_param *params)
{
	t_plot	*tmp;

	tmp = params->plot_head;
	while (tmp)
	{
		bresenham(tmp->x1, tmp->x2, tmp->y1, tmp->y2, params);
		tmp = tmp->next;
	}
}

t_plot		*get_plots(t_param *params, int row, int col, char axis)
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
