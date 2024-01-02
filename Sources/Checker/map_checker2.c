/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:33:20 by febonaer          #+#    #+#             */
/*   Updated: 2023/12/27 12:20:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static void	getplayerdir(t_map *map, char c)
{
	if (c == 69)
	{
		map->dir_y = 1;
		map->plane_y = 0;
		map->plane_x = 0.66;
	}
	else if (c == 78)
		map->dir_x = -1;
	else if (c == 83)
	{
		map->dir_x = 1;
		map->plane_x = 0;
		map->plane_y = -0.66;
	}
	else
	{
		map->dir_y = -1;
		map->plane_y = 0;
		map->plane_x = -0.66;
	}
}

static bool	map_precheck2(char *stack, t_map *map)
{
	int	i;

	i = 0;
	while (stack[i] && (stack[i] == 48 || ft_isspace(stack[i])
			|| stack[i] == '\n' || stack[i] == 49 || stack[i] == 69
			|| stack[i] == 78 || stack[i] == 83 || stack[i] == 87))
	{
		if (stack[i] == 69 || stack[i] == 78
			|| stack[i] == 83 || stack[i] == 87)
		{
			if (map->check == true)
				return (false);
			getplayerdir(map, stack[i]);
			map->check = true;
		}
		i++;
	}
	return (true);
}

static bool	map_precheck(int fd, t_map *map)
{
	char	*stack;
	char	*line;

	stack = NULL;
	line = get_next_line(fd);
	if (!line)
		ft_exit("Error\nAllocation failed\n", map);
	while (line != NULL)
	{
		stack = ft_strjoin(stack, line);
		if (!stack)
			ft_exit("Error\nAllocation failed\n", map);
		free(line);
		line = get_next_line(fd);
	}
	if (!map_precheck2(stack, map))
	{
		free(stack);
		return (false);
	}
	map->maparray = ft_split(stack, '\n');
	if (!map->maparray)
		ft_exit("Error\nAllocation failed\n", map);
	free(stack);
	return (true);
}

bool	map_extractor(int fd, t_map *map)
{
	sprite_checker(map);
	map->check = false;
	if (!map_precheck(fd, map) || map->check == false || !map_valid(map))
		ft_exit("Error\nSyntax error in the map\n", map);
	return (true);
}
