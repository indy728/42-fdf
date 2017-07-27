/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:06:23 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/20 02:31:16 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	insert_err(t_err **root, t_err *node, t_options *options)
{
	int	value;

	value = 0;
	if (*root == NULL)
		*root = node;
	else
	{
		value = ft_strcmp((*root)->path, node->path);
		value = options->r ? value *= -1 : value;
		if (value > 0 && !options->f)
			insert_err(&(*root)->left, node, options);
		else
			insert_err(&(*root)->right, node, options);
	}
}

t_err		*err_tree(t_err *root, char *path, char *er_msg, t_options *options)
{
	t_err	*node;

	if (!(node = ft_memalloc(sizeof(t_err))))
	{
		perror("memory allocation error");
		exit(1);
	}
	ft_bzero(node, sizeof(t_err));
	node->path = ft_strdup(path);
	node->er_msg = ft_strdup(er_msg);
	insert_err(&root, node, options);
	return (root);
}
