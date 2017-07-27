/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 03:07:02 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/20 01:59:51 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	insert_elem(t_file **tree_top, t_file *new_leaf, t_options *options)
{
	long	value;

	value = 0;
	if (*tree_top == NULL)
		*tree_top = new_leaf;
	else
	{
		if (options->big_s)
			value = new_leaf->size - (*tree_top)->size;
		else if (options->t)
		{
			if (!(value = new_leaf->time - (*tree_top)->time))
				value = new_leaf->ntime - (*tree_top)->ntime;
		}
		if (!value)
			value = ft_strcmp((*tree_top)->name, new_leaf->name);
		value = options->r ? value *= -1 : value;
		if (value > 0 && !options->f)
			insert_elem(&(*tree_top)->left, new_leaf, options);
		else
			insert_elem(&(*tree_top)->right, new_leaf, options);
	}
}
