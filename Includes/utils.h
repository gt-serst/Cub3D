/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:14:23 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/22 17:14:25 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_map
{
	char	**maparray;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*ceiling;
	char	*floor;
	int		map_x;
	int		map_y;
	double	hexfloor;
	double	hexceiling;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	tex_pos;
	double	time;
	double	old_time;
	double	perp_wall_dist;
	bool	check;
}	t_map;

int		ft_strlen(const char *str);
int		ft_putstr_fd(char const *s, int fd);
char	**ft_split(char const *str, char c);
int		ft_isnumber(char *s);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
void	ft_exit(char *str, t_map *map);
char	*ft_strjoin(char *s1, char const *s2);

#endif
