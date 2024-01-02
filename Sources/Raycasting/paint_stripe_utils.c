/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_stripe_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:23:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/22 15:24:25 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static double	get_wall_hit_coordinate(t_map *map)
{
	double	wall_x;

	if (map->side == 0)
		wall_x = map->pos_y + map->perp_wall_dist * map->ray_dir_y;
	else
		wall_x = map->pos_x + map->perp_wall_dist * map->ray_dir_x;
	wall_x -= floor((wall_x));
	return (wall_x);
}

int	get_tex_x_coordinate(t_map *map)
{
	int	tex_x;

	tex_x = (int)(get_wall_hit_coordinate(map) * TEX_WIDTH);
	if (map->side == 0 && map->ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (map->side == 1 && map->ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

int	get_tex_y_coordinate(t_map *map, double step)
{
	int		tex_y;

	tex_y = (int)map->tex_pos;
	map->tex_pos += step;
	return (tex_y);
}

int	get_draw_start(int line_height)
{
	int	draw_start;

	draw_start = HEIGHT / 2 - line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int	get_draw_end(int line_height)
{
	int	draw_end;

	draw_end = HEIGHT / 2 + line_height / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	return (draw_end);
}
