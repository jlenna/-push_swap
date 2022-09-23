/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:24:35 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:41:53 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char	*str)
{
	int					i;
	int					n;
	unsigned long long	u;

	i = 0;
	n = 0;
	u = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		n++;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (ft_isdigit((int)str[i]) == 1)
	{
		u = (u * 10) + (str[i] - '0');
		i++;
	}
	if (n == 1)
		u = -u;
	return ((long long)u);
}
