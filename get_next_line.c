/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:13:03 by tamounir          #+#    #+#             */
/*   Updated: 2024/12/24 20:08:58 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reading(int fd, char *buffer)
{
	int		readed;
	char	*buff;

	readed = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (readed != 0)
	{
		buff = malloc((size_t)BUFFER_SIZE + 1);
		readed = read(fd, buff, BUFFER_SIZE);
		if ((!buffer && readed == 0) || readed == -1)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		buff[readed] = '\0';
		buffer = ft_strjoin(buffer, buff);
		if (ncheck(buffer))
			break ;
	}
	return (buffer);
}

static char	*gettline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		line = malloc(i + 1);
	if (buffer[i] == '\n')
		line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*getrest(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = ft_strlen(line);
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	j = 0;
	while (buffer[i++])
		j++;
	rest = malloc(j + 1);
	if (!rest)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	free (buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	char		*line;

	if (fd < 0 || (size_t)BUFFER_SIZE + 1 > INT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = reading(fd, buff);
	if (!tmp)
	{
		if (buff)
			free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = tmp;
	line = gettline(buff);
	buff = getrest(line, buff);
	return (line);
}
