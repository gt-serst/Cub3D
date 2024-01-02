/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:58:14 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/27 10:29:57 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	strafe_right(t_window *window)
{
	double	new_dir_x;
	double	new_dir_y;

	new_dir_x = window->map->dir_y;
	new_dir_y = window->map->dir_x * -1;
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x
				+ new_dir_x)][(int)(window->map->pos_y)]) == 1)
		window->map->pos_x += new_dir_x / 2;
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x)]
		[(int)(window->map->pos_y + new_dir_y)]))
		window->map->pos_y += new_dir_y / 2;
}

void	strafe_left(t_window *window)
{
	double	new_dir_x;
	double	new_dir_y;

	new_dir_y = window->map->dir_x;
	new_dir_x = window->map->dir_y * -1;
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x
				+ new_dir_x)][(int)(window->map->pos_y)]) == 1)
		window->map->pos_x += new_dir_x / 2;
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x)]
		[(int)(window->map->pos_y + new_dir_y)]))
		window->map->pos_y += new_dir_y / 2;
}

void	move_backward(t_window *window)
{
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x
				+ window->map->dir_x)][(int)(window->map->pos_y)]) == 1)
		window->map->pos_x += window->map->dir_x / 2;
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x)]
		[(int)(window->map->pos_y + window->map->dir_y)]))
		window->map->pos_y += window->map->dir_y / 2;
}

void	move_forward(t_window *window)
{
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x
				- window->map->dir_x)][(int)(window->map->pos_y)]) == 1)
		window->map->pos_x -= window->map->dir_x / 2;
	if (is_walkable(window->map->maparray[(int)(window->map->pos_x)]
		[(int)(window->map->pos_y - window->map->dir_y)]))
		window->map->pos_y -= window->map->dir_y / 2;
}
