/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:34:59 by jlenna            #+#    #+#             */
/*   Updated: 2021/10/27 14:55:51 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (*str1 != '\0') && (*str2 != '\0'))
	{
		if (*str1 == *str2)
		{
			i++;
			str1++;
			str2++;
		}
		else
			return ((unsigned char)*str1 - (unsigned char)*str2);
	}
	if (i < n)
		return ((unsigned char)*str1 - (unsigned char)*str2);
	return (0);
}
