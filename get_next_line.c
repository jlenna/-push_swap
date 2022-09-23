/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:15 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:48:08 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_remainnew(char *remain)
{
	int		a;
	int		b;
	char	*new;

	a = 0;
	b = 0;
	while (remain[a] && remain[a] != '\n')
		a++;
	if (remain[a] == '\0')
	{
		free(remain);
		return (NULL);
	}
	new = malloc((gnl_strlen(remain) - a + 1) * sizeof(char));
	if (!new)
		return (NULL);
	a++;
	while (remain[a])
		new[b++] = remain[a++];
	new[b] = '\0';
	free(remain);
	return (new);
}

char	*ft_getline(char *remain)
{
	int		a;
	char	*str;

	a = 0;
	if (!remain[a])
		return (NULL);
	while (remain[a] && remain[a] != '\n')
		a++;
	str = malloc(sizeof(char) * (a + 2));
	if (!str)
		return (NULL);
	a = 0;
	while (remain[a] && remain[a] != '\n')
	{
		str[a] = remain[a];
		a++;
	}
	if (remain[a] == '\n')
	{
		str[a] = remain[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char	*ft_readline(int fd, char *remain, char *buffer)
{
	int		byte;

	byte = 1;
	while (byte != 0 && !ft_findend(remain))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		remain = gnl_strjoin(remain, buffer);
	}
	free(buffer);
	return (remain);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remain;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	remain = ft_readline(fd, remain, buffer);
	if (!remain)
		return (NULL);
	line = ft_getline(remain);
	remain = ft_remainnew(remain);
	return (line);
}
