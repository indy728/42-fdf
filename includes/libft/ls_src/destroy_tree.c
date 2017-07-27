/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:57:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/23 23:20:54 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	destroy_tree(t_file *root)
{
	if (root)
	{
		destroy_tree(root->left);
		destroy_tree(root->right);
		ft_strdel(&root->name);
		ft_strdel(&root->mode);
		ft_strdel(&root->owner);
		ft_strdel(&root->group);
		ft_strdel(&root->link);
		free(root);
		root = NULL;
	}
}
