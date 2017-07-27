/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 02:57:09 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/24 00:08:52 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static char	*read_date(time_t *ftime, char *date, int n)
{
	char	*dtime;
	time_t	now;

	dtime = ctime(ftime);
	if (time(&now) - *ftime < SIXMO || n == 21)
	{
		date = ft_strncat(date, dtime + 4, n - 1);
		date[n] = '\0';
	}
	else
	{
		date = ft_strncat(date, dtime + 4, 7);
		date = ft_strcat(date, " ");
		date = ft_strncat(date, dtime + 20, 4);
		date[n] = '\0';
	}
	return (date);
}

static void	owner_group_ops(t_file *file, t_options *options, char *date)
{
	if (options->o && options->g)
	{
		ft_printf("%10s %2u %6d %s %s", file->mode, file->nlink,
			file->size, date, file->name);
	}
	else if (options->o)
	{
		ft_printf("%10s %2u %7s %6d %s %s", file->mode, file->nlink,
			file->owner, file->size, date, file->name);
	}
	else
	{
		ft_printf("%10s %2u %8s %6d %s %s", file->mode, file->nlink,
			file->group, file->size, date, file->name);
	}
}

static void	long_print(t_file *file, t_options *options, int n)
{
	char		*date;

	date = ft_strnew(21);
	date = read_date(&file->time, date, n);
	if (options->s)
		ft_printf("%2d ", file->blocks);
	if (options->o || options->g)
		owner_group_ops(file, options, date);
	else
	{
		ft_printf("%10s %2u %7s %8s %6d %s %s", file->mode, file->nlink,
			file->owner, file->group, file->size, date, file->name);
	}
	if (options->p && file->mode[0] == 'd')
		ft_printf("/");
	if (file->link)
		ft_printf(" -> %s", file->link);
	ft_putendl("");
	ft_strdel(&date);
}

static void	print_recursive(t_file *file, t_options *options)
{
	int			n;

	n = 13;
	if (options->big_t)
		n = 21;
	if (file)
	{
		if (file->left)
			print_recursive(file->left, options);
		if (options->l)
			long_print(file, options, n);
		else
			ft_printf("%s\n", file->name);
		if (file->right)
			print_recursive(file->right, options);
	}
}

void		print_tree(t_file *file, t_options *options,
								char *path, unsigned int blocks)
{
	if (options->nl)
		ft_putendl("");
	if (options->folder)
		ft_printf("%s:\n", path);
	if (file)
	{
		if (options->l && options->total)
			ft_printf("total %u\n", blocks);
		print_recursive(file, options);
		options->nl = 1;
	}
	options->folder = 1;
	options->total = 1;
}
