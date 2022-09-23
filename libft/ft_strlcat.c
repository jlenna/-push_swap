/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:27:00 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/11 20:10:04 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	i;
	size_t	a;
	size_t	res;
	size_t	l;

	n = 0;
	a = ft_strlen((char *)src);
	i = ft_strlen(dest);
	l = ft_strlen(dest);
	if (size > ft_strlen(dest) && (size > 0))
	{
		res = a + ft_strlen(dest);
		while ((src[n]) && ((n + l) < (size - 1)))
		{
			dest[i] = src[n];
			i++;
			n++;
		}
		dest[i] = '\0';
	}
	else
		res = a + size;
	return (res);
}
