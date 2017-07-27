/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:40:08 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/04 21:17:47 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlstr(char *big, char *little)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!big || !little)
		return (0);
	while (big[i])
	{
		j = 0;
		k = i;
		while (big[i] == little[j])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return (k);
		}
		i = k;
		i++;
	}
	if (*little == '\0')
		return (0);
	return (-1);
}
