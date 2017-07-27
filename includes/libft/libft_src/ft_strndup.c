/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:35:05 by kmurray           #+#    #+#             */
/*   Updated: 2017/06/28 17:37:25 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *str, size_t size)
{
	char	*dup;

	if (!(dup = ft_strnew(size + 1)))
		return (NULL);
	return (ft_strncpy(dup, str, size));
}
