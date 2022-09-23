/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:34:25 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/09 15:40:16 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*a;
	size_t	k;

	k = n * size;
	a = malloc(k);
	if (!a)
		return (NULL);
	ft_memset(a, 0, k);
	return (a);
}
