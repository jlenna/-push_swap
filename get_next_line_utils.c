/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:57:19 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:48:04 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_findend(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		if (str[a] == '\n')
			return ((char *)str + a);
		a++;
	}
	return (0);
}

int	gnl_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*gnl_strjoin(char *remain, char *buffer)
{
	int		a;
	int		b;
	char	*str;

	if (!remain)
	{
		remain = malloc(sizeof(char) * 1);
		remain[0] = '\0';
	}
	if (!remain || ! buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(remain) + ft_strlen(buffer) + 1));
	if (str == 0)
		return (NULL);
	a = -1;
	b = 0;
	if (remain)
		while (remain[++a] != '\0')
			str[a] = remain[a];
	while (buffer[b])
		str[a++] = buffer[b++];
	str[a] = '\0';
	free(remain);
	return (str);
}
