/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_legend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 02:44:32 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/15 15:59:04 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*wf_print_legend(t_param *params, char *path, char bottom)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	x = 40;
	y = 10;
	if (bottom)
		y = 1230;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		mlx_string_put(params->mlx, params->win, x, y, 0xffffff, line);
		y += 20;
		ft_strdel(&line);
	}
	close(fd);
	return (NULL);
}
