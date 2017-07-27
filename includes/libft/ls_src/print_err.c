/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 02:57:09 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/19 19:53:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		print_err(t_err *root)
{
	if (root)
	{
		if (root->left)
			print_err(root->left);
		ft_printf("./ft_ls: %s: %s\n", root->path, root->er_msg);
		if (root->right)
			print_err(root->right);
	}
}
