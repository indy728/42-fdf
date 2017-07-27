/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_malloc_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:37:42 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/01 14:56:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_malloc_error(char *func, size_t size)
{
	char *ascii_size;

	ascii_size = ft_umaxtoa_base(size, 10);
	ft_putstr_fd(func, 2);
	ft_putstr_fd(": unable to allocate memory of size ", 2);
	ft_putendl_fd(ascii_size, 2);
	ft_freezero(ascii_size, ft_strlen(ascii_size));
	exit(1);
}
