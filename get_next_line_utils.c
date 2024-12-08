/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <marvin@42.fr>                    +#+  +:+       +#+        */
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
	int		i;
	int		j;
	char	*conc;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	conc = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!conc)
		return (NULL);
	i = -1;
	while (s1[++i])
		conc[i] = s1[i];
	j = -1;
	while (s2[++j])
		conc[i++] = s2[j];
	conc[i] = '\0';
	free(s1);
	free(s2);
	return (conc);
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
	size_t	i;
	char	*p;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < count)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
