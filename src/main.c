/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/20 03:47:57 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*make_array(char **split, int size)
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

void	put_sqr(void *mlx, void *win, int x, int y, int color)
{
	int i = 0;
	int j;
	int size = 2;

	while (i < size)
	{
		j = 0;
		while (j < size)
			mlx_pixel_put(mlx, win, (x - size / 2) + j++, (y - size / 2) + i, color);
		++i;
	}
}

void	print_list(t_list *begin_list)
{
	t_list	*scout;
	int		*arr;
	int 	count;

	scout = begin_list;
	while (scout->next)
	{
		arr = (int *)scout->content;
		count = 0;
		while (count < scout->content_size / sizeof(int))
		{
			ft_printf("% 3d", arr[count++]);
		}
		ft_printf("\n");
		scout = scout->next;
	}
	count = 0;
	while (count < scout->content_size / sizeof(int))
		ft_printf("% 3d", arr[count++]);
	ft_putendl("");
}

t_param	*param_init(t_list *begin_list, char *title)
{
	t_param	*params;

	params = (t_param *)malloc(sizeof(t_param));
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, 1500, 1500, title);
	params->grid_size = GRID;
	params->height = HEIGHT;
	params->startx = STARTX;
	params->starty = STARTY;
	params->alpha = 0;
	params->beta = 0;
	params->map = begin_list;
	return (params);
}

void	get_map(int fd, t_list **begin_list)
{
	char	*line;
	char	**split;
	int		i;
	int		*arr;

	line = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i])
			++i;
		arr = make_array(split, i);
		ft_lstadd_back(begin_list, ft_lstnew(arr, sizeof(int) * i));
		free(split);
		free(arr);
	}
	ft_freezero(line, ft_strlen(line));
	close(fd);
}

int main(int ac, char **av)
{
	t_param	*params;
	char	*line;
	int		fd;
	t_list	*begin_list;
	
	if (ac == 2)
	{
		line = ft_strnew(1);
		fd = open(av[1], O_RDONLY);
		get_map(fd, &begin_list);
		print_list(begin_list);
		params = param_init(begin_list, av[1]);
		while(mlx_key_hook(params->win, my_key_funct, params))
			mlx_loop(params->mlx);
	}
	return (0);
}
