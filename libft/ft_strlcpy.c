/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:30:18 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/11 20:10:55 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (!size)
		return (ft_strlen(src));
	if (size > 0)
	{	
		while (src[a] && (a < size - 1))
		{
			*(dst + a) = *(src + a);
			a++;
		}
	}
	*(dst + a) = '\0';
	a = ft_strlen(src);
	return (a);
}
