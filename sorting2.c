/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:56 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 19:57:56 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_a(t_all *all)
{
	all->stack_a->flag = -1;
	ra(all, 1);
}

int	find_next_b(t_all *all)
{
	int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		ra_a(all);
		return (1);
	}
	else if (all->stack_a->index == min)
		ra_a(all);
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		ra_a(all);
	}
	return (0);
}

void	med_min_max_b(t_all *all)
{
	int	min;
	int	max;
	int	a;

	if (all->len_b == 0)
		return ;
	a = all->len_b;
	min = all->stack_b->index;
	max = all->stack_b->index;
	while (a > 0)
	{
		if (min > all->stack_b->index)
			min = all->stack_b->index;
		if (max < all->stack_b->index)
			max = all->stack_b->index;
		all->stack_b = all->stack_b->next;
		a--;
	}
	all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
}

void	go_b_to_a(t_all *all)
{
	int	a;

	a = all->len_b;
	med_min_max_b(all);
	while (a-- > 0)
	{
		if (find_next_b(all))
			continue ;
		if (all->stack_b->index > all->med)
		{
			all->stack_b->flag++;
			pa(all, 1);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}
