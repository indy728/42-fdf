/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_expose_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:53:08 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/15 19:15:02 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_expose_funct(t_param *params)
{
	static int	i;

	if (i)
	{
		mlx_clear_window(params->mlx, params->win);
		wf_get_plot_map(params);
	}
	i = 1;
	return (1);
}
