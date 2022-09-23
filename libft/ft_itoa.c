/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:17:03 by jlenna            #+#    #+#             */
/*   Updated: 2021/11/11 19:35:10 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;
	long	n1;

	n1 = n;
	i = ft_len(n);
	s = (char *)ft_calloc(sizeof(char) * (i + 1), 1);
	if (!s)
		return (NULL);
	if (n1 == 0)
		s[0] = '0';
	if (n1 < 0)
	{
		s[0] = '-';
		n1 = n1 * (-1);
	}
	i--;
	while (n1)
	{
		s[i] = n1 % 10 + '0';
		n1 = n1 / 10;
		i--;
	}
	return (s);
}
