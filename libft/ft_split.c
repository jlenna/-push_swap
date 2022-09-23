/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:52:15 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/14 13:11:16 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_func(char const *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{	
			j = i;
			while ((s[i] != c) && s[i])
				i++;
			arr[n] = ft_substr(s, j, i - j);
			if (!(arr[n]))
				ft_free(arr);
			n++;
		}
		if (s[i])
			i++;
	}
	arr[n] = 0;
	return (arr);
}

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	char	**res;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	arr = (char **)ft_calloc(sizeof(char *) * (count + 1), 1);
	if (!arr)
		return (NULL);
	res = ft_func(s, c, arr);
	return (res);
}
