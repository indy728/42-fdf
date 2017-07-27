/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 18:01:46 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/05 00:23:56 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubstr(char *big, char *little, char *sub)
{
	char	*new;
	int		begin;
	int		end;

	if ((begin = ft_strlstr(big, little)) < 0)
		return (NULL);
	end = ft_strlnstr(big, little);
	new = ft_strnew(ft_strlen(big) + ft_strlen(sub) - ft_strlen(little));
	new = ft_strncpy(new, big, begin);
	new = ft_strcat(new, sub);
	new = ft_strcat(new, big + end);
	return (new);
}
