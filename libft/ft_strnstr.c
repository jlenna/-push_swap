/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:25 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:45:40 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s2);
	if (j == 0)
		return ((char *)s1);
	while ((i < n) && (s1[i]))
	{
		if (ft_strncmp((const char *)&s1[i], s2, j) == 0)
		{
			if (i + j > n)
				return (NULL);
			return ((char *)&s1[i]);
		}
		else
			i++;
	}
	return (NULL);
}
