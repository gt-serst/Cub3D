/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:13:09 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/27 12:19:15 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static bool	launch_ray(t_map *map)
{
	map->map_x = (int)(map->pos_x);
	map->map_y = (int)(map->pos_y);
	map->delta_dist_x = get_delta_dist_x(map);
	map->delta_dist_y = get_delta_dist_y(map);
	map->side_dist_x = get_side_dist_x(map, map->delta_dist_x);
	map->side_dist_y = get_side_dist_y(map, map->delta_dist_y);
	dda_algo(map);
	return (compute_perp_wall_dist(map));
}

static void	side_y_hit(t_map *map, t_window *window, t_img *img, int x)
{
	if (map->ray_dir_y < 0)
		paint_vertical_stripe(map, img, x, &window->image[2]);
	else
		paint_vertical_stripe(map, img, x, &window->image[3]);
}

static void	side_x_hit(t_map *map, t_window *window, t_img *img, int x)
{
	if (map->ray_dir_x < 0)
		paint_vertical_stripe(map, img, x, &window->image[0]);
	else
		paint_vertical_stripe(map, img, x, &window->image[1]);
}

void	ft_raycasting(t_map *map, t_window *window)
{
	int		x;
	double	camera_x;
	t_img	img;

	img.reference = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (img.reference == NULL)
		ft_mlx_error(map, window, "Error\nFailed to create an image\n");
	img.addr = mlx_get_data_addr(img.reference,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	if (img.addr == NULL)
		ft_mlx_error(map, window, "Error\nFailed to get the image address\n");
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * (double)x / (double)(WIDTH) - 1;
		map->ray_dir_x = map->dir_x + map->plane_x * camera_x;
		map->ray_dir_y = map->dir_y + map->plane_y * camera_x;
		if (launch_ray(map) == false)
			side_x_hit(map, window, &img, x);
		else
			side_y_hit(map, window, &img, x);
		x++;
	}
	window->img = img.reference;
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
}
