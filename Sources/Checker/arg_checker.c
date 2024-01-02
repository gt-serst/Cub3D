/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:32:55 by febonaer          #+#    #+#             */
/*   Updated: 2023/12/27 16:17:23 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

bool	arg_checker(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	if (argc != 2)
		return (false);
	str = ft_split(argv[1], '/');
	if (!str)
		return (false);
	j = 0;
	while (str[j])
		j++;
	i = ft_strlen(str[j - 1]);
	if (i < 5 || str[j - 1][i - 1] != 'b' || str[j - 1][i - 2] != 'u'
		|| str[j - 1][i - 3] != 'c' || str[j - 1][i - 4] != '.'
		|| str[j - 1][i - 5] == '.')
	{
		ft_free_array(str);
		return (false);
	}
	ft_free_array(str);
	return (true);
}
