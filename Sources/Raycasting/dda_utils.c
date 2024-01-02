/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:19:25 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/22 15:22:08 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

double	get_delta_dist_x(t_map *map)
{
	double	delta_dist_x;

	if (map->ray_dir_x == 0)
		delta_dist_x = 1e30;
	else
		delta_dist_x = fabs(1 / map->ray_dir_x);
	return (delta_dist_x);
}

double	get_delta_dist_y(t_map *map)
{
	double	delta_dist_y;

	if (map->ray_dir_y == 0)
		delta_dist_y = 1e30;
	else
		delta_dist_y = fabs(1 / map->ray_dir_y);
	return (delta_dist_y);
}

double	get_side_dist_x(t_map *map, double delta_dist_x)
{
	double	side_dist_x;

	if (map->ray_dir_x < 0)
	{
		map->step_x = -1;
		side_dist_x = (map->pos_x - map->map_x) * delta_dist_x;
	}
	else
	{
		map->step_x = 1;
		side_dist_x = (map->map_x + 1.0 - map->pos_x) * delta_dist_x;
	}
	return (side_dist_x);
}

double	get_side_dist_y(t_map *map, double delta_dist_y)
{
	double	side_dist_y;

	if (map->ray_dir_y < 0)
	{
		map->step_y = -1;
		side_dist_y = (map->pos_y - map->map_y) * delta_dist_y;
	}
	else
	{
		map->step_y = 1;
		side_dist_y = (map->map_y + 1.0 - map->pos_y) * delta_dist_y;
	}
	return (side_dist_y);
}

bool	compute_perp_wall_dist(t_map *map)
{
	if (map->side == 0)
	{
		map->perp_wall_dist = map->side_dist_x - map->delta_dist_x;
		return (false);
	}
	else
		map->perp_wall_dist = map->side_dist_y - map->delta_dist_y;
	return (true);
}
