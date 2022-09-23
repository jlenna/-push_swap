/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:51 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 19:57:51 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_b(t_all *all)
{
	int	a;
	int	b;
	int	c;

	a = all->stack_b->value;
	b = all->stack_b->next->value;
	c = all->stack_b->prev->value;
	if (a < b && a < c && b > c)
	{
		rrb(all, 1);
		sb(all, 1);
	}
	else if (a > b && a < c && b < c)
		sb(all, 1);
	else if (a < b && a > c && b > c)
		rrb(all, 1);
	else if (a > b && a > c && b < c)
		rb(all, 1);
	else if (a > b && a > c && b > c)
	{
		sb(all, 1);
		rrb(all, 1);
	}
}

void	simple_b_next(t_all *all, int f)
{
	if (all->len_b == 2)
	{
		if (all->stack_b->index > all->stack_b->next->index)
			sb(all, 1);
	}
	else
		sort_3_b(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->len_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
		all->stack_a->flag == -1)
		{	
			pa(all, 1);
			ra_a(all);
		}
		else
			ra_a(all);
	}
	while (f == all->stack_a->flag && f != -1 && \
	all->stack_a->index + 1 == all->stack_a->prev->index)
		ra_a(all);
}

void	simple_b(t_all *all)
{
	int		index;
	int		flag;
	int		a;

	a = all->len_b;
	index = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	while (a > 3)
	{
		if (index == all->stack_b->index)
		{
			pa(all, 1);
			ra_a(all);
			index++;
		}
		else
			pa(all, 1);
		a--;
	}
	simple_b_next(all, flag);
}
