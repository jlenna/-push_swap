/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:56:23 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:39:34 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_duplicate(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_valid(char **arr)
{
	int			i;
	int			j;
	long long	temp;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-')
				j++;
			if (!ft_isdigit(arr[i][j]))
			{
				free_array(arr);
				ft_error();
			}
			j++;
		}
		temp = ft_atoi(arr[i]);
		ft_valid_next(temp, arr);
		i++;
	}
}

void	ft_valid_next(long long temp, char **arr)
{
	if (temp < INT_MIN || temp > INT_MAX)
	{
		free_array(arr);
		ft_error();
	}
	if (!ft_duplicate(arr))
	{
		free_array(arr);
		ft_error();
	}
}
