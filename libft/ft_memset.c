/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:28:56 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/14 12:13:04 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	dest1 = (unsigned char *)dest;
	while (n != 0)
	{
		*dest1++ = c1;
		n--;
	}
	return (dest);
}
