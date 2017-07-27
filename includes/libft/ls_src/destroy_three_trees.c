/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_three_trees.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:57:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/20 03:27:58 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	destroy_err(t_err *err)
{
	if (err)
	{
		destroy_err(err->left);
		destroy_err(err->right);
		if (err->path)
			ft_strdel(&err->path);
		if (err->er_msg)
			ft_strdel(&err->er_msg);
		free(err);
		err = NULL;
	}
}

void		destroy_three_trees(t_err *err, t_file *ndir, t_file *dir)
{
	destroy_err(err);
	destroy_tree(ndir);
	destroy_tree(dir);
}
