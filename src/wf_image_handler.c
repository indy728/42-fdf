/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_image_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 22:33:48 by kmurray           #+#    #+#             */
/*   Updated: 2017/08/15 14:53:36 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_param *params)
{
	t_img	*img;

	img = params->img;
	ft_bzero(img, sizeof(t_img));
	img->ptr = mlx_new_image(params->mlx, WINX, WINY);
	img->pixels = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
}

void	image_init(t_param *params)
{
	t_img	*new;

	if (!(new = (t_img *)ft_memalloc(sizeof(t_img))))
	{
		ft_printf("Failed to allocate memory for image pointer.\n");
		memdel_and_exit(params);
	}
	params->img = new;
	clear_image(params);
}

void	image_put(t_param *params)
{
	int	i;

	wf_print_legend(params, "text/legend1.txt");
	i = 98;
	while (i++ <= 1201)
		img_pixel_put(params->img, i, 99, 0xffffff);
	i = 99;
	while (i++ <= 1200)
	{
		img_pixel_put(params->img, 99, i, 0xffffff);
		img_pixel_put(params->img, 1202, i, 0xffffff);
	}
	i = 99;
	while (i++ <= 1201)
		img_pixel_put(params->img, i, 1201, 0xffffff);
	mlx_put_image_to_window(params->mlx, params->win, params->img->ptr, 0, 0);
	mlx_destroy_image(params->mlx, params->img->ptr);
	clear_image(params);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	i;

	i = (x + y * img->size_line / sizeof(int));
	img->pixels[i] = color;
}
