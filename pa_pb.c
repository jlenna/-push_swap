/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:14 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:01:52 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_all *all)
{
	t_stack	*temp;

	temp = all->stack_b->next;
	all->stack_b->prev->next = all->stack_b->next;
	all->stack_b->next->prev = all->stack_b->prev;
	if (all->stack_a)
	{
		all->stack_b->prev = all->stack_a->prev;
		all->stack_b->next = all->stack_a;
		all->stack_a->prev->next = all->stack_b;
		all->stack_a->prev = all->stack_b;
		all->stack_a = all->stack_b;
	}
	else
	{
		all->stack_a = all->stack_b;
		all->stack_a->next = all->stack_a;
		all->stack_a->prev = all->stack_a;
	}
	all->stack_b = temp;
}

void	do_pb(t_all *all)
{
	t_stack	*temp;

	temp = all->stack_a->next;
	all->stack_a->prev->next = all->stack_a->next;
	all->stack_a->next->prev = all->stack_a->prev;
	if (all->stack_b)
	{
		all->stack_a->prev = all->stack_b->prev;
		all->stack_a->next = all->stack_b;
		all->stack_b->prev->next = all->stack_a;
		all->stack_b->prev = all->stack_a;
		all->stack_b = all->stack_a;
	}
	else
	{
		all->stack_b = all->stack_a;
		all->stack_a->next = all->stack_b;
		all->stack_a->prev = all->stack_b;
	}
	all->stack_a = temp;
}

void	pa(t_all *all, int f)
{
	if (all->len_b == 0)
		return ;
	do_pa(all);
	if (all->len_b == 1)
		all->stack_b = NULL;
	all->len_a++;
	all->len_b--;
	if (f)
		ft_putendl_fd("pa", 1);
}

void	pb(t_all *all, int f)
{
	if (all->len_a == 0)
		return ;
	do_pb(all);
	if (all->len_a == 1)
		all->stack_a = NULL;
	all->len_b++;
	all->len_a--;
	if (f)
		ft_putendl_fd("pb", 1);
}
