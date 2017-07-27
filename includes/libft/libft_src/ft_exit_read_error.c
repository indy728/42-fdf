/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_read_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:37:42 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/05 18:22:21 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_read_error(char *func, char **line, int fd)
{
	char	*itoa;

	ft_putstr_fd(func, 2);
	ft_putstr_fd(": unable to read line from fd  ", 2);
	ft_putendl_fd((itoa = ft_itoa(fd)), 2);
	ft_strdel(line);
	ft_strdel(&itoa);
	exit(1);
}
