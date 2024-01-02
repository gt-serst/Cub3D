/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:04:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/27 14:31:16 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static void	init_raycast(t_map *map)
{
	map->pos_x = 0;
	map->pos_y = 0;
	map->dir_x = 0;
	map->dir_y = 0;
	map->ray_dir_x = 0;
	map->ray_dir_y = 0;
	map->plane_x = 0;
	map->plane_y = 0.66;
	map->delta_dist_x = 0;
	map->delta_dist_y = 0;
	map->side_dist_x = 0;
	map->side_dist_y = 0;
	map->step_x = 0;
	map->step_y = 0;
	map->side = 0;
	map->tex_pos = 0;
	map->time = 0;
	map->old_time = 0;
	map->perp_wall_dist = 0;
	map->check = false;
}

static t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!map)
		exit(EXIT_FAILURE);
	map->maparray = NULL;
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
	map->ceiling = NULL;
	map->floor = NULL;
	map->map_x = 0;
	map->map_y = 0;
	map->hexfloor = 0;
	map->hexceiling = 0;
	init_raycast(map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	map = init_map();
	if (!arg_checker(argc, argv))
		ft_exit("Error\nFile extension is not '.cub'\n", map);
	if (!map_checker(argv, map))
		ft_exit("Error\nWrong map format\n", map);
	launch_graphic_env(map);
	return (0);
}
