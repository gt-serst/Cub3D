/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:33:44 by febonaer          #+#    #+#             */
/*   Updated: 2023/12/27 16:17:56 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static unsigned int	creatergb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static char	**ft_minisplit(char *rgb, t_map *map)
{
	char	**colors;

	colors = ft_split(rgb, ',');
	if (!colors)
		ft_exit("Error\nAllocation failed\n", map);
	return (colors);
}

static void	check_sprite_rgb(char *rgb, double *hex, int r, t_map *map)
{
	int		i;
	int		num;
	int		g;
	char	**colors;

	g = 0;
	colors = ft_minisplit(rgb, map);
	i = -1;
	while (colors[++i])
	{
		if (!ft_isnumber(colors[i]))
			ft_exit("Error\nRGB syntax error: not a digit\n", map);
		num = ft_atoi(colors[i]);
		free(colors[i]);
		if (num > 255 || num < 0)
			ft_exit("Error\nRGB syntax error\n", map);
		if (i == 0)
			r = num;
		else if (i == 1)
			g = num;
	}
	free(colors);
	if (i != 3)
		ft_exit("Error\nRGB syntax error\n", map);
	*hex = (double)(creatergb(r, g, num));
}

static void	check_sprite_path(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	**str;
	int		j;

	str = ft_split(path, '/');
	if (!str)
		ft_exit("Error\nAllocation failed\n", map);
	j = 0;
	while (str[j])
		j++;
	i = ft_strlen(str[j - 1]);
	if (i < 5 || str[j - 1][i - 1] != 'm' || str[j - 1][i - 2] != 'p'
		|| str[j - 1][i - 3] != 'x' || str[j - 1][i - 4]
		!= '.' || str[j - 1][i - 5] == '.')
	{
		ft_free_array(str);
		ft_exit("Error\nSprite error: not a .xpm\n", map);
	}
	ft_free_array(str);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nCannot open sprite file\n", map);
	close(fd);
}

void	sprite_checker(t_map *map)
{
	int	r;

	r = 0;
	check_sprite_path(map->north, map);
	check_sprite_path(map->south, map);
	check_sprite_path(map->east, map);
	check_sprite_path(map->west, map);
	check_sprite_rgb(map->ceiling, &map->hexceiling, r, map);
	check_sprite_rgb(map->floor, &map->hexfloor, r, map);
}
