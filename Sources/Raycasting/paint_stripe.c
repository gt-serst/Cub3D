/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_stripe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:22:37 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/22 15:25:25 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	paint_vertical_stripe(t_map *map, t_img *image,
	int x, t_img *texture)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;
	double	step;

	if (map->perp_wall_dist == 0)
		map->perp_wall_dist = 1e30;
	line_height = (int)(HEIGHT / map->perp_wall_dist);
	draw_start = get_draw_start(line_height);
	draw_end = get_draw_end(line_height);
	step = 1.0 * TEX_HEIGHT / line_height;
	map->tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
	y = draw_start;
	while (y++ < draw_end)
		my_mlx_pixel_put(image, x, y, get_pixel_color(texture,
				get_tex_x_coordinate(map), get_tex_y_coordinate(map, step)));
	y = -1;
	while (y++ < draw_start)
		my_mlx_pixel_put(image, x, y, (int)map->hexceiling);
	y = HEIGHT;
	while (y-- > draw_end)
		my_mlx_pixel_put(image, x, y, (int)map->hexfloor);
}
