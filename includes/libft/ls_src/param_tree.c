/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 21:42:27 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/20 02:01:10 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_file		*param_tree(t_file *root, char *path, t_options *options)
{
	t_file	*node;

	if (!(node = ft_memalloc(sizeof(t_file))))
	{
		perror("memory allocation error");
		exit(1);
	}
	ft_bzero(node, sizeof(t_file));
	node->name = ft_strdup(path);
	node->blocks = get_dirattributes(node, options);
	insert_elem(&root, node, options);
	return (root);
}
