/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:01 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 19:57:03 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*struct_init(char	**arr)
{
	t_all	*all;
	int		a;

	a = 0;
	while (arr[a])
		a++;
	all = malloc(sizeof(t_all));
	if (all == NULL)
		return (NULL);
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->min_a = 1;
	all->med = 0;
	all->len_a = a;
	all->len_b = 0;
	return (all);
}

void	arr_to_stack(char **arr, t_all *all)
{
	int		a;
	int		len;
	int		number;
	int		*unsorted;
	int		*sorted;

	a = -1;
	len = 0;
	while (arr[++a])
		len++;
	unsorted = malloc(sizeof(int) * (len + 1));
	sorted = malloc(sizeof(int) * (len + 1));
	a = 0;
	while (a < len)
	{
		number = ft_atoi(arr[a]);
		unsorted[a] = number;
		sorted[a] = number;
		a++;
	}
	bubblesort(unsorted, sorted, len, all);
}

void	bubblesort(int *unsorted, int *sorted, int len, t_all *all)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j + 1];
				sorted[j + 1] = sorted[j];
				sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
	create_stack(all, sorted, unsorted, len);
}

void	create_stack(t_all *all, int *sorted, int *unsorted, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (unsorted[i] == sorted[j])
			{
				add_list(&all->stack_a, create_list(unsorted[i], j + 1));
				j++;
			}
			j++;
		}
		i++;
	}
	all->min_a = sorted[0];
	free(unsorted);
	free(sorted);
}

void	free_array(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
