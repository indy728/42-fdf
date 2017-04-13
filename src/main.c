/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/13 00:54:02 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	my_key_funct(int keycode, t_param *param)
{
	void	*tmp;
	if (keycode == C)
	{
		ft_putstr("clearing window\n");
		mlx_clear_window(param->mlx, param->win);
	}
	if (keycode == D)
	{
		ft_putstr("destroying window\n");
		mlx_destroy_window(param->mlx, param->win);
	}
	if (keycode == ESC)
	{
		ft_putstr("GET ME THE FUCK OUTTA HERE!\n");
		mlx_destroy_window(param->mlx, param->win);
		free (param);
		exit (0);
	}
	return (1);
}

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
			printf("% 3d", arr[count++]);
	//		ft_putnbr(arr[count++]);
		}
		printf("\n");
		scout = scout->next;
	}
	count = 0;
	while (count < scout->content_size / sizeof(int))
		printf("% 3d", arr[count++]);
	//	ft_putnbr(arr[count++]);
}

void	print_iso2d(t_list *begin_list, void *mlx, void *win)
{
	int x = 50;
	int y = 50;
	int i = 0;
	int *arr;
	int	x_inc = 2 * GRID;
	int	y_inc = GRID;
	int n = 0;
	t_list	*scout;
	unsigned int	r = 0xFF0000;
	unsigned int	g = 0x00FF00;
	unsigned int	b = 0x0000FF;
	unsigned int color = r + g + b;

	scout = begin_list;
	while (scout->next)
	{
		arr = scout->content;
		i = 0;
		while (i < scout->content_size / sizeof(int))
		{
			x = 300 + i * x_inc - n * x_inc;
			y = 50 + i * y_inc + n * y_inc;
			put_sqr(mlx, win, x, y - arr[i], color - arr[i] * (0x0100 * 5 + 0x010000 * 5));
			++i;
		}
		scout = scout->next;
		++n;
	}
	arr = scout->content;
	i = 0;
	while (i < scout->content_size / sizeof(int))
	{
		x = 300 + i * x_inc - n * x_inc;
		y = 50 + i * y_inc + n * y_inc;
		put_sqr(mlx, win, x, y - arr[i], color - arr[i] * (0x0100 * 10 + 0x010000 * 10));
		++i;
	}
}

void	put_list(t_list *begin_list, void *mlx, void *win, int color)
{
	t_list	*scout;
	int		*arr;
	int 	count;
	int		x;
	int		y;
	int		line;

	scout = begin_list;
	y = 50;
	while (scout->next)
	{
		arr = (int *)scout->content;
		x = 50;
		count = 0;
		while (count < scout->content_size / sizeof(int))
		{
			if (arr[count++] == 0)
				put_sqr(mlx, win, x, y, 0x00FFFFFF);
			else
				put_sqr(mlx, win, x, y, color);
			line = 0;
			while (line++ < 49)
				mlx_pixel_put(mlx, win, x, y + line, 0x00FFFFFF);
			line = 0;
			if (count < scout->content_size / sizeof(int))
			{
				while (line++ < 49)
					mlx_pixel_put(mlx, win, x + line, y, 0x00FFFFFF);
			}
			x += 50;
		}
		printf("\n");
		y += 50;
		scout = scout->next;
	}
	count = 0;
	x = 50;
	while (count < scout->content_size / sizeof(int))
	{
		if (arr[count++] == 0)
			put_sqr(mlx, win, x, y, 0x00FFFFFF);
		else
			put_sqr(mlx, win, x, y, color);
		line = 0;
		if (count < scout->content_size / sizeof(int))
		{
			while (line++ < 49)
				mlx_pixel_put(mlx, win, x + line, y, 0x00FFFFFF);
		}
		x += 50;
	}
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		pulse;
	t_param	*params;
	int color = 0x000000FF;
	
	if (ac > 1)
	{
		int		gnl;
		char	*line;
		int		fd;
		char	**split;
		int		i;
		int		*arr;
		t_list *begin_list;

		line = ft_strnew(1);
		begin_list = NULL;
		fd = open(av[1], O_RDONLY);
		while ((gnl = get_next_line(fd, &line)) > 0)
		{
			i = 0;
			split = ft_strsplit(line, ' ');
			while (split[i])
				++i;
			arr = make_array(split, i);
			ft_lstadd_back(&begin_list, ft_lstnew(arr, sizeof(int) * i));
			free(split);
			free(arr);
		}
		print_list(begin_list);
		close(fd);
		ft_freezero(line, ft_strlen(line));
		mlx = mlx_init();
		win = mlx_new_window(mlx, 1500, 1500, "mlx 42");
		print_iso2d(begin_list, mlx, win);
		//put_list(begin_list, mlx, win, color);
		params = (t_param *)malloc(sizeof(t_param));
		params->mlx = mlx;
		params->win = win;
		ft_lstdel(&begin_list, ft_freezero);
		while (mlx_key_hook(win, my_key_funct, params))
			mlx_loop(mlx);
	}
	return (0);
}
