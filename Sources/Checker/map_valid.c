/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:33:36 by febonaer          #+#    #+#             */
/*   Updated: 2023/12/22 14:33:37 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static bool	ft_isvalidchar(t_map *map, int x, int y)
{
	if (map->maparray[x][y] != '1' && map->maparray[x][y] != '0'
		&& map->maparray[x][y] != '4' && map->maparray[x][y] != '3'
		&& map->maparray[x][y] != 'N' && map->maparray[x][y] != 'E'
		&& map->maparray[x][y] != 'S' && map->maparray[x][y] != 'W')
		return (false);
	return (true);
}

static bool	ft_exist(t_map *map, int x, int y)
{
	int	count;

	count = 0;
	while (map->maparray[count])
		count++;
	if (x - 1 < 0 || y - 1 < 0 || x + 1 >= count
		|| y + 1 >= ft_strlen(map->maparray[x]))
		return (false);
	if (!map->maparray[x][y - 1] || !ft_isvalidchar(map, x, y - 1))
		return (false);
	if (!map->maparray[x][y + 1] || !ft_isvalidchar(map, x, y + 1))
		return (false);
	if (!map->maparray[x - 1][y] || !ft_isvalidchar(map, x - 1, y))
		return (false);
	if (!map->maparray[x + 1][y] || !ft_isvalidchar(map, x + 1, y))
		return (false);
	if (ft_strlen(map->maparray[x - 1]) < y
		|| ft_strlen(map->maparray[x + 1]) < y)
		return (false);
	return (true);
}

bool	ft_iszero(t_map *map, int x, int y)
{
	if (map->maparray[x][y - 1] == 0 || map->maparray[x][y - 1] == 'N'
		|| map->maparray[x][y - 1] == 'E' || map->maparray[x][y - 1] == 'S'
		|| map->maparray[x][y - 1] == 'W')
		return (ft_recursive_checker(map, x, y - 1));
	if (map->maparray[x][y + 1] == 0 || map->maparray[x][y + 1] == 'N'
		|| map->maparray[x][y + 1] == 'E' || map->maparray[x][y + 1] == 'S'
		|| map->maparray[x][y + 1] == 'W')
		return (ft_recursive_checker(map, x, y + 1));
	if (map->maparray[x - 1][y] == 0 || map->maparray[x - 1][y] == 'N'
		|| map->maparray[x - 1][y] == 'E' || map->maparray[x - 1][y] == 'S'
		|| map->maparray[x - 1][y] == 'W')
		return (ft_recursive_checker(map, x - 1, y));
	if (map->maparray[x + 1][y] == 0 || map->maparray[x + 1][y] == 'N'
		|| map->maparray[x + 1][y] == 'E' || map->maparray[x + 1][y] == 'S'
		|| map->maparray[x + 1][y] == 'W')
		return (ft_recursive_checker(map, x + 1, y));
	return (true);
}

bool	ft_recursive_checker(t_map *map, int x, int y)
{
	if (map->maparray[x][y] == 'N' || map->maparray[x][y] == 'E'
		|| map->maparray[x][y] == 'S' || map->maparray[x][y] == 'W')
		map->maparray[x][y] = '4';
	else
		map->maparray[x][y] = '3';
	if (!ft_exist(map, x, y))
		return (false);
	if (!ft_iszero(map, x, y))
		return (false);
	return (true);
}

bool	map_valid(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->maparray[x])
	{
		y = 0;
		while (map->maparray[x][y])
		{
			if (map->maparray[x][y] == '0' || map->maparray[x][y] == 'N'
				|| map->maparray[x][y] == 'E' || map->maparray[x][y] == 'S'
				|| map->maparray[x][y] == 'W')
			{
				if (!ft_recursive_checker(map, x, y))
					ft_exit("Error\nInvalid map\n", map);
			}
			y++;
		}
		x++;
	}
	return (true);
}
