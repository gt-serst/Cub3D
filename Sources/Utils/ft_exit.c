/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:05:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/27 13:48:11 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static void	ft_free_path(t_map *map)
{
	if (map->north != NULL)
		free(map->north);
	if (map->south != NULL)
		free(map->south);
	if (map->east != NULL)
		free(map->east);
	if (map->west != NULL)
		free(map->west);
	if (map->ceiling != NULL)
		free(map->ceiling);
	if (map->floor != NULL)
		free(map->floor);
}

void	ft_exit(char *str, t_map *map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		if (map->maparray != NULL && map->maparray[i] != NULL)
		{
			while (map->maparray[i] != NULL)
			{
				free(map->maparray[i]);
				i++;
			}
			free(map->maparray);
		}
		ft_free_path(map);
		free(map);
	}
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
