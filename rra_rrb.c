/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:20 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 19:57:20 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all *all, int f)
{
	if (all->len_a > 1)
		all->stack_a = all->stack_a->prev;
	if (f)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_all *all, int f)
{
	if (all->len_b > 1)
		all->stack_b = all->stack_b->prev;
	if (f)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_all *all, int f)
{
	ra(all, 0);
	rb(all, 0);
	if (f)
		ft_putendl_fd("rrr", 1);
}
