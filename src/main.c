#include "fdf.h"

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

int main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		pulse;
	t_param	*params;
	int color = 0x000000FF;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 350)
	{
		x = 50;
		while (x < 350)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			if (color < 0x0000FF00)
			{
				color += 0x00000100;
				color -= 0x00000001;
			}
			++x;
		}
		color = 0x000000FF;
		++y;
	}
	params = (t_param *)malloc(sizeof(t_param));
	params->mlx = mlx;
	params->win = win;
	while (mlx_key_hook(win, my_key_funct, params))
	mlx_loop(mlx);
}
