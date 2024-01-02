/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_graphic_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:10:15 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/27 14:16:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	ft_mlx_error(t_map *map, t_window *window, char *str)
{
	(void)window;
	ft_exit(str, map);
}

static void	find_player_coords(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->maparray[x])
	{
		y = 0;
		while (map->maparray[x][y])
		{
			if (map->maparray[x][y] == '4')
			{
				map->pos_x = (double)x + 0.5;
				map->pos_y = (double)y + 0.5;
				break ;
			}
			y++;
		}
		x++;
	}
}

static void	get_image(t_window *window, char *path, int i)
{
	window->image[i].reference = mlx_xpm_file_to_image(window->mlx, path,
			&window->image[i].line_length, &window->image[i].endian);
	if (window->image[i].reference == NULL)
		ft_mlx_error(window->map, window, "Error\nFailed to load an image\n");
	window->image[i].addr = mlx_get_data_addr(window->image[i].reference,
			&window->image[i].bits_per_pixel,
			&window->image[i].line_length, &window->image[i].endian);
	if (window->image[i].addr == NULL)
		ft_mlx_error(window->map, window,
			"Error\nFailed to get the image address\n");
}

static void	init_image(t_window *window)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			get_image(window, window->map->north, i);
		if (i == 1)
			get_image(window, window->map->south, i);
		if (i == 2)
			get_image(window, window->map->west, i);
		if (i == 3)
			get_image(window, window->map->east, i);
		i++;
	}
}

void	launch_graphic_env(t_map *map)
{
	t_window	window;

	window.map = map;
	find_player_coords(map);
	window.mlx = mlx_init();
	if (window.mlx == NULL)
		ft_mlx_error(map, &window, "Error\nFailed to launch the MLX\n");
	window.mlx_win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "CUB3D");
	if (window.mlx_win == NULL)
		ft_mlx_error(map, &window, "Error\nCouldn't connect to the window\n");
	init_image(&window);
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	if (window.img == NULL)
		ft_mlx_error(map, &window, "Error\nFailed to create an image\n");
	window.addr = mlx_get_data_addr(window.img,
			&window.bits_per_pixel, &window.line_length, &window.endian);
	if (window.addr == NULL)
		ft_mlx_error(map, &window,
			"Error\nFailed to get the image address\n");
	ft_raycasting(map, &window);
	mlx_hook(window.mlx_win, 17, 0, ft_close, &window);
	mlx_hook(window.mlx_win, 2, (1L << 0), ft_handle_input, &window);
	mlx_loop(window.mlx);
}
