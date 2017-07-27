/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:40:08 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/04 21:17:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlnstr(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little || !big)
		return (0);
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j])
		{
			++i;
			++j;
			if (little[j] == '\0')
				return (i);
		}
		i++;
	}
	if (*little == '\0')
		return (ft_strlen(big));
	return (-1);
}
