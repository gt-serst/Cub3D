/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:33:10 by febonaer          #+#    #+#             */
/*   Updated: 2023/12/27 16:01:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static bool	get_path(char *str, char **path)
{
	int	i;
	int	j;

	i = 3;
	if (str[1] == ' ')
		i--;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	j = i;
	while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t')
		j++;
	*path = malloc(sizeof(char) * (j - i + 1));
	if (!path)
		return (false);
	j = -1;
	while (str[i] != '\0' && str[i] != ' '
		&& str[i] != '\t' && str[i] != '\n')
	{
		(*path)[++j] = str[i];
		i++;
	}
	(*path)[++j] = '\0';
	return (true);
}

static bool	is_valid_line2(char *str, t_map *map)
{
	int	check;

	check = 0;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' '
		&& map->north == NULL && get_path(str, &map->north))
		check = 1;
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' '
		&& map->south == NULL && get_path(str, &map->south))
		check = 1;
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' '
		&& map->east == NULL && get_path(str, &map->east))
		check = 1;
	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' '
		&& map->west == NULL && get_path(str, &map->west))
		check = 1;
	if (str[0] == 'C' && str[1] == ' ' && map->ceiling == NULL
		&& get_path(str, &map->ceiling))
		check = 1;
	if (str[0] == 'F' && str[1] == ' ' && map->floor == NULL
		&& get_path(str, &map->floor))
		check = 1;
	if (check == 1)
		return (true);
	return (false);
}

static bool	is_valid_line(char *str, t_map *map)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	if (is_valid_line2(str, map))
		check = 1;
	else
	{
		while (str[++i])
		{
			if (str[i] != ' ' && str[i] != 9 && str[i] != 10
				&& str[i] != 11 && str[i] != 12 && str[i] != 13)
				return (false);
		}
		check = 1;
	}
	if (map->north != NULL && map->south != NULL && map->east != NULL
		&& map->west != NULL && map->ceiling != NULL && map->floor != NULL)
		map->check = true;
	if (check == 1)
		return (true);
	return (false);
}

static bool	cub_extractor(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && map->check == false)
	{
		if (!is_valid_line(line, map))
		{
			free (line);
			return (false);
		}
		free (line);
		if (map->check == false)
			line = get_next_line(fd);
	}
	if (map->check == false)
		return (false);
	if (!map_extractor(fd, map))
		return (false);
	return (true);
}

bool	map_checker(char **argv, t_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (false);
	if (!cub_extractor(fd, map))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
