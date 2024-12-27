/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:13:03 by tamounir          #+#    #+#             */
/*   Updated: 2024/12/26 20:38:36 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reading(int fd, char *buffer)
{
	ssize_t	readed;
	char	*tmp;

	if (BUFFER_SIZE <= 0 || (size_t)BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
	tmp = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
	if (!tmp)
		return (free(buffer), buffer = NULL, NULL);
	readed = 1;
	while (readed > 0 && ncheck(buffer) != 1)
	{
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), free(tmp), NULL);
		tmp[readed] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(tmp), NULL);
	}
	return (free(tmp), buffer);
}

static char	*gettline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	nextline = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	if (!nextline)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		nextline[j++] = buffer[i++];
	nextline[j] = '\0';
	free(buffer);
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || (size_t)BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = reading(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = gettline(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_next_line(buffer);
	return (line);
}
