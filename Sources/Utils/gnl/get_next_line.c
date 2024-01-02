/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:20:19 by febonaer          #+#    #+#             */
/*   Updated: 2023/12/22 15:15:35 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../Includes/cub3d.h"

//read(fd, NULL, 0) non accepte pour les tests de fsoares
//if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 || fd > FD_MAX)
static int	ft_checkread(int fd)
{
	if (fd < 0 || fd > FD_MAX)
		return (0);
	return (1);
}

//READ ET AJOUTE PEU A PEU A LA STACK JUSQU A TOMBER SUR UN \N ou EOF.
static char	*read_line(int fd, char *stack)
{
	char	*buffer;
	int		reader;

	buffer = NULL;
	buffer = malloc(sizeof(char) * (50 + 1));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (!(ft_strchr(stack, '\n')) && reader != 0)
	{
		reader = read(fd, buffer, 50);
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		stack = ft_strjoin_gnl(stack, buffer);
	}
	free(buffer);
	return (stack);
}

//EXTRAIT UNE LIGNE TERMINEE PAR \N OU EOF DE LA STACK.
static char	*get_myline(char *stack)
{
	char	*line;
	int		i;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

//MISE A JOUR DE LA STACK APRES EXTRACTION DE LA LIGNE A RENVOYER.
static char	*get_stack(char *stack)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	j = ft_strlen(stack);
	res = malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
	{
		res[j++] = stack[i++];
	}
	res[j] = '\0';
	free(stack);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (!ft_checkread(fd))
		return (NULL);
	stack = read_line(fd, stack);
	if (!stack)
		return (NULL);
	line = get_myline(stack);
	stack = get_stack(stack);
	return (line);
}

/*int	main()
  {
  int		fd;
  char	*line;

  fd = 0;
  fd = open("test2.txt", O_RDONLY);
  line = get_next_line(fd);
  printf("%s", line);
  line = get_next_line(fd);
  printf("%s", line);
  line = get_next_line(fd);
  printf("%s", line);
  line = get_next_line(fd);
  printf("%s", line);
  line = get_next_line(fd);
  printf("%s", line);
  line = get_next_line(fd);
  printf("%s", line);
  line = get_next_line(fd);
  printf("%s", line);
  return (0);
  }*/
