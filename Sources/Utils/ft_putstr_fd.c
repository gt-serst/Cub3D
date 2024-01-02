/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonaert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:59:07 by fbonaert          #+#    #+#             */
/*   Updated: 2023/10/23 16:04:01 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	ft_putstr_fd(char const *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	if (s)
		write(fd, s, len);
	return (len);
}
