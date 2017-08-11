/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/10 01:04:07 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*make_array(char **split, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = ft_memalloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = ft_atoi(split[i]);
		++i;
	}
	return (arr);
}

static void		get_map(int fd, t_list **begin_list)
{
	char	*line;
	char	**split;
	int		i;
	int		*arr;

	*begin_list = NULL;
	while (get_next_line(fd, &line))
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i])
			++i;
		arr = make_array(split, i);
		ft_lstcat(begin_list, ft_lstnew(arr, sizeof(int) * i));
		free(split);
		free(arr);
	}
	ft_freezero(line, ft_strlen(line));
	close(fd);
}

static t_bool	validate_map(t_list **begin_list)
{
	t_list	*tmp;
	size_t	len;

	if (*begin_list)
	{
		tmp = *begin_list;
		len = tmp->content_size;
		while (tmp)
		{
			if (tmp->content_size != len)
			{
				ft_lstdel(begin_list, ft_freezero);
				return (0);
			}
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

static void		invalid_map(char *str, int i)
{
	ft_printf("Invalid file: %s.\n", str);
	exit(i);
}

int				main(int ac, char **av)
{
	t_param	*params;
	int		fd;
	t_list	*begin_list;

	if (ac >= 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			invalid_map(INV_FILE, 1);
		get_map(fd, &begin_list);
		if (!validate_map(&begin_list))
			invalid_map(ARRAY, 0);
		params = param_init(begin_list, ac, av);
		wf_get_plot_map(params);
		while (mlx_key_hook(params->win, my_key_funct, params))
			mlx_loop(params->mlx);
	}
	return (0);
}
