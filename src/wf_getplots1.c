/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_getplots1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:31:50 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/09 02:02:57 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			wf_plotcat(t_plot **head, t_plot *new)
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

static t_list	*get_array(t_list *head, int row)
{
	int		n;
	t_list	*scout;

	n = 0;
	scout = head;
	while (n++ < row)
		scout = scout->next;
	return (scout);
}

t_plot			*plot_2d(t_param *params, int row, int col, char axis)
{
	int		*arr;
	t_plot	*plot;
	t_list	*scout;

	plot = ft_memalloc(sizeof(t_plot));
	scout = get_array(params->map, row);
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
		arr = scout->next->content;
		plot->x2 = getx(col, row + 1, arr[col], params);
		plot->y2 = gety(col, row + 1, arr[col], params);
		plot->z2 = arr[col];
	}
	return (plot);
}

t_max			*wf_getmax(t_plot *head)
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

void			wf_get_plot_map(t_param *params)
{
	int		i;
	int		row;
	t_list	*scout;

	row = 0;
	scout = params->map;
	while (scout)
	{
		i = -1;
		while (++i < scout->content_size / sizeof(int))
		{
			if (i + 1 < scout->content_size / sizeof(int))
				wf_plotcat(&params->plot_head, plot_2d(params, row, i, 'x'));
			if (scout->next)
				wf_plotcat(&params->plot_head, plot_2d(params, row, i, 'y'));
		}
		scout = scout->next;
		++row;
	}
	params->max = wf_getmax(params->plot_head);
	if (params->max->xmin < 0)
		plot_shiftx(params->plot_head, -1 * params->max->xmin);
	if (params->max->ymin < 0)
		plot_shifty(params->plot_head, -1 * params->max->ymin);
	wf_putplots(params);
}
