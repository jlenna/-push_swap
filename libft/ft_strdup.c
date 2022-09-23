/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:41:50 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/11 20:05:14 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	void	*s;
	size_t	n;

	n = ft_strlen(str);
	s = malloc(n + 1);
	if (!s)
		return (NULL);
	s = ft_memcpy(s, str, n + 1);
	return ((char *)s);
	free(s);
}
