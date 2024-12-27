/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:13:23 by tamounir          #+#    #+#             */
/*   Updated: 2024/12/07 18:13:24 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	new = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (new == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
		new[j++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

int	ncheck(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!count || !size)
		return (0);
	else
		mem = malloc(count * size);
	if (!mem)
		return (free(mem), NULL);
	while (i < size * count)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
