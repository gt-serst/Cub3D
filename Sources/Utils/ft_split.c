/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:06:01 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/22 17:06:03 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

static int	ft_nb_split(char *str, char c)
{
	int	i;
	int	nb;
	int	bl;

	i = 0;
	nb = 0;
	while (str[i])
	{
		bl = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			if (!bl)
				nb += 1;
			bl = 1;
			i++;
		}
	}
	return (nb);
}

static char	*ft_cut_split(char *str, char c, int *i)
{
	int		j;
	int		len;
	char	*strnew;

	j = 0;
	len = 0;
	while (str[*i] == c && str[*i])
		*i += 1;
	while (str[*i + len] != c && str[*i + len])
		len++;
	strnew = malloc(sizeof(char) * (len + 1));
	if (!strnew)
		return (NULL);
	while (j < len)
	{
		strnew[j] = str[*i];
		j++;
		*i += 1;
	}
	strnew[j] = '\0';
	return (strnew);
}

char	**ft_split(char const *str, char c)
{
	int			i;
	int			offset;
	int			tab_size;
	char		**res;

	i = 0;
	offset = 0;
	if (!str)
		return (NULL);
	tab_size = ft_nb_split((char *)str, c);
	res = malloc(sizeof(char *) * (tab_size + 1));
	if (!res)
		return (NULL);
	while (i < tab_size)
	{
		res[i] = ft_cut_split((char *)str, c, &offset);
		i++;
	}
	res[i] = NULL;
	return (res);
}
