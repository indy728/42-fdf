/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:48:03 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/03 14:00:29 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmove(char *dest, char **src)
{
	char	*tmp;

	if (!dest)
		return (NULL);
	tmp = *src;
	*src = dest;
	ft_strdel(&tmp);
	return (*src);
}
