/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:38 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:11:46 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_a(t_all *all)
{
	int	a;
	int	b;
	int	c;

	a = all->stack_a->value;
	b = all->stack_a->next->value;
	c = all->stack_a->prev->value;
	if (a < b && a < c && b > c)
	{
		rra(all, 1);
		sa(all, 1);
	}
	else if (a > b && a < c && b < c)
		sa(all, 1);
	else if (a < b && a > c && b > c)
		rra(all, 1);
	else if (a > b && a > c && b < c)
		ra(all, 1);
	else if (a > b && a > c && b > c)
	{
		sa(all, 1);
		rra(all, 1);
	}
}

void	sort_4_a(t_all *all)
{
	int	small;
	int	a;

	a = all->len_a;
	small = all->stack_a->index;
	while (a > 0)
	{
		if (small > all->stack_a->index)
			small = all->stack_a->index;
		all->stack_a = all->stack_a->next;
		a--;
	}
	if (all->stack_a->prev->index == small)
		rra(all, 1);
	while (all->stack_a->index != small)
		ra(all, 1);
	pb(all, 1);
	sort_3_a(all);
	pa(all, 1);
}

void	sort_5_a(t_all *all)
{
	int	small;
	int	a;

	a = all->len_a;
	small = all->stack_a->index;
	while (a > 0)
	{
		if (small > all->stack_a->index)
			small = all->stack_a->index;
		all->stack_a = all->stack_a->next;
		a--;
	}
	while (all->stack_a->index != small)
		ra(all, 1);
	pb(all, 1);
	sort_4_a(all);
	pa(all, 1);
}

void	simple_a(t_all *all)
{
	if (all->len_a == 2)
	{
		if (all->stack_a->index > all->stack_a->next->index)
			ra(all, 1);
	}
	else if (all->len_a == 3)
		sort_3_a(all);
	else if (all->len_a == 4)
		sort_4_a(all);
	else if (all->len_a == 5)
		sort_5_a(all);
}
