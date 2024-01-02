/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:13:22 by febonaer          #+#    #+#             */
/*   Updated: 2022/10/20 13:15:33 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_MAX 1024

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *left_str, char *buff);
char	*ft_strchr(const char *s, int c);

#endif
