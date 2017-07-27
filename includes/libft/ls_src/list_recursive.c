/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:03:11 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/20 02:00:53 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	list_recursive(char *path, t_file *root, t_options *options)
{
	char	*tmp;

	if (root->left)
		list_recursive(path, root->left, options);
	if (root->mode[0] == 'd' && ft_strcmp(".", root->name) &&
			ft_strcmp("..", root->name))
	{
		tmp = ft_strjoin(path, "/");
		tmp = ft_strmove(ft_strjoin(tmp, root->name), &tmp);
		build_tree(tmp, options);
		free(tmp);
	}
	if (root->right)
		list_recursive(path, root->right, options);
}
