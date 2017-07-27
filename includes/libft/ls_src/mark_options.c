/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:51:04 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/20 02:22:52 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	time_stamp(char op, t_options *options)
{
	if (op == 't')
	{
		options->c = 0;
		options->u = 0;
		options->t = 1;
	}
	else if (op == 'c')
	{
		options->c = 1;
		options->u = 0;
	}
	else if (op == 'u')
	{
		options->c = 0;
		options->u = 1;
	}
}

static void	long_display(char op, t_options *options)
{
	options->l = 1;
	if (op == 'o')
		options->o = 1;
	else if (op == 'g')
		options->g = 1;
	else if (op == 'n')
		options->n = 1;
}

static void	check_box_helper(char op, t_options *options)
{
	if (op == 'S')
		options->big_s = 1;
	else if (op == 'T')
		options->big_t = 1;
	else if (op == 's')
		options->s = 1;
	else if (op == 'A')
		options->big_a = 1;
	else if (op == 'p')
		options->p = 1;
	else
		options->f = 1;
}

static void	check_box(char op, t_options *options)
{
	if (op == 'l' || op == 'g' || op == 'o' || op == 'n')
		long_display(op, options);
	else if (op == 'R')
		options->big_r = 1;
	else if (op == 'a')
		options->a = 1;
	else if (op == 'r')
		options->r = 1;
	else if (op == 't' || op == 'c' || op == 'u')
		time_stamp(op, options);
	else if (op == '1')
		options->l = 0;
	else if (op == 'S' || op == 'T' || op == 's' || op == 'A' ||
			op == 'p' || op == 'f')
		check_box_helper(op, options);
	else
	{
		ft_putstr(USAGE);
		exit(0);
	}
}

int			mark_options(int ac, char **av, t_options *options, int i)
{
	char	*str;
	int		j;

	str = av[i];
	while (i < ac && str[0] == '-')
	{
		j = 0;
		while (str[++j])
			check_box(str[j], options);
		++i;
		str = av[i];
	}
	return (i);
}
