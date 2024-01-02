/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:14:00 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/27 16:11:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

bool	ft_iszero(t_map *map, int x, int y);
bool	ft_recursive_checker(t_map *map, int x, int y);
bool	map_valid(t_map *map);
bool	arg_checker(int argc, char **argv);
bool	map_checker(char **argv, t_map *map);
bool	map_extractor(int fd, t_map *map);
void	sprite_checker(t_map *map);
void	ft_free_array(char **str);

#endif
