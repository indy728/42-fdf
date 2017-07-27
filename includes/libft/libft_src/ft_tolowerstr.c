/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolowerstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:44:51 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 17:15:19 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolowerstr(char *str)
{
	char	tmp[ft_strlen(str)];
	int		i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			tmp[i] += ('a' - 'A');
		else
			tmp[i] = str[i];
		++i;
	}
	tmp[i] = '\0';
	return (str);
}
