/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:07:20 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/01 16:06:53 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_r(char **arr)
{
	char	**dup;
	int		i;

	i = -1;
	if (!(dup = ft_memalloc(sizeof(char *) * (ft_size_r(arr) + 1))))
		return (NULL);
	while (arr[++i])
		dup[i] = ft_strdup(arr[i]);
	dup[i] = NULL;
	return (dup);
}
