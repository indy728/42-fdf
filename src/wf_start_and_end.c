/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_start_and_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 19:52:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/26 20:02:03 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	memdel_and_exit(t_param *params)
{
		ft_putstr("ESC: Ending program.\n");
		mlx_destroy_window(params->mlx, params->win);
		ft_lstdel(&params->map, ft_freezero);
		free (params);
		exit (0);
}

t_param	*param_init(t_list *begin_list, char *title)
{
	t_param	*params;

	params = (t_param *)malloc(sizeof(t_param));
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, 1300, 1300, title);
	params->grid_size = GRID;
	params->height = HEIGHT;
	params->plot_head = NULL;
	params->max = NULL;
	params->alpha = 0;
	params->beta = 0;
	params->gamma = 0;
	params->map = begin_list;
	return (params);
}
