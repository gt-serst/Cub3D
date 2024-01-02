/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:55:48 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/22 17:04:21 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	rotate_left(t_window *window)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = window->map->dir_x;
	window->map->dir_x = window->map->dir_x
		* cos(0.1) - window->map->dir_y * sin(0.1);
	window->map->dir_y = old_dir_x * sin(0.1)
		+ window->map->dir_y * cos(0.1);
	old_plane_x = window->map->plane_x;
	window->map->plane_x = window->map->plane_x
		* cos(0.1) - window->map->plane_y * sin(0.1);
	window->map->plane_y = old_plane_x * sin(0.1)
		+ window->map->plane_y * cos(0.1);
}

void	rotate_right(t_window *window)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = window->map->dir_x;
	window->map->dir_x = window->map->dir_x
		* cos(-0.1) - window->map->dir_y * sin(-0.1);
	window->map->dir_y = old_dir_x * sin(-0.1)
		+ window->map->dir_y * cos(-0.1);
	old_plane_x = window->map->plane_x;
	window->map->plane_x = window->map->plane_x
		* cos(-0.1) - window->map->plane_y * sin(-0.1);
	window->map->plane_y = old_plane_x * sin(-0.1)
		+ window->map->plane_y * cos(-0.1);
}
