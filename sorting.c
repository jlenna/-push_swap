/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:44 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:14:00 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_all *all)
{
	int		a;
	t_stack	*check;

	check = all->stack_a;
	a = all->len_a;
	while (a > 1)
	{
		if (check->index > check->next->index)
			return (0);
		check = check->next;
		a--;
	}
	return (1);
}

void	sorted_go_a(t_all *all)
{
	while (all->stack_b->prev->flag == -1)
		rrb(all, 1);
	while (all->stack_b->flag == -1)
	{
		pa(all, 1);
		ra(all, 1);
	}
}

void	med_min_max_a(t_all *all)
{
	int	min;
	int	max;
	int	a;

	if (all->len_a == 0)
		return ;
	a = all->len_a;
	min = all->stack_a->index;
	max = all->stack_a->index;
	while (a > 0)
	{
		if (min > all->stack_a->index)
			min = all->stack_a->index;
		if (max < all->stack_a->index)
			max = all->stack_a->index;
		all->stack_a = all->stack_a->next;
		a--;
	}
	all->min = min;
	all->max = max;
	all->med = (min + max) / 2;
}

void	do_first(t_all *all)
{
	int	a;

	a = all->len_a;
	med_min_max_a(all);
	while (a > 0)
	{
		if (all->stack_a->index <= all->med)
		{
			pb(all, 1);
			if (all->stack_b->index == all->min)
			{
				all->stack_b->flag = -1;
				rb(all, 1);
			}
		}
		else
		{
			if (all->len_b == all->max - all->med + 1)
				break ;
			else
				ra(all, 1);
		}
		a--;
	}
	sorted_go_a(all);
}
