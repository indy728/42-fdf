/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:40:35 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/05 22:06:07 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printfile(char *path)
{
	int		fd;
	char	*line;

	if ((fd = open(path, O_RDONLY)) < 0)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
}
