/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:14:31 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/23 23:19:40 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	dir_tree(t_file *root, t_options *options)
{
	if (root)
	{
		if (root->left)
			dir_tree(root->left, options);
		build_tree(root->name, options);
		if (root->right)
			dir_tree(root->right, options);
	}
}

static void	print_and_destroy(t_err *err, t_file *ndir,
									t_file *dir, t_options *options)
{
	print_err(err);
	print_tree(ndir, options, NULL, 0);
	options->folder = 1;
	dir_tree(dir, options);
	destroy_three_trees(err, ndir, dir);
}

static void	three_trees(int ac, char **av, int i, t_options *options)
{
	DIR			*dirp;
	t_file		*ndir;
	t_file		*dir;
	t_err		*err;

	ndir = NULL;
	dir = NULL;
	err = NULL;
	while (i < ac)
	{
		if (!(dirp = opendir(av[i])))
		{
			if (errno == 20)
				ndir = param_tree(ndir, av[i], options);
			else
				err = err_tree(err, av[i], strerror(errno), options);
			errno = 0;
		}
		else
			dir = param_tree(dir, av[i], options);
		++i;
		if (dirp)
			(void)closedir(dirp);
	}
	print_and_destroy(err, ndir, dir, options);
}

int			main(int ac, char **av)
{
	int				i;
	t_options		options;

	ft_bzero(&options, sizeof(t_options));
	i = mark_options(ac, av, &options, 1);
	if (i == ac)
	{
		options.total = 1;
		build_tree(".", &options);
	}
	else
		three_trees(ac, av, i, &options);
	return (0);
}
