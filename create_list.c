/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:56:50 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 19:56:56 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_list(int value, int index)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->value = value;
	list->index = index;
	list->flag = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	add_list(t_stack **stack_a, t_stack *new)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp)
	{
		if (temp->prev)
		{
			new->next = temp;
			new->prev = temp->prev;
			temp->prev->next = new;
			temp->prev = new;
		}
		else
		{
			temp->prev = new;
			temp->next = new;
			new->prev = temp;
			new->next = temp;
		}
	}
	else
		*stack_a = new;
}

void	free_stacks(t_all *all)
{
	t_stack	*temp;

	while (all->len_a != 0)
	{
		temp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = temp;
		all->len_a--;
	}
	while (all->len_b != 0)
	{
		temp = all->stack_b->next;
		free(all->stack_b);
		all->stack_b = NULL;
		all->stack_b = temp;
		all->len_b--;
	}
	free(all);
	exit(0);
}
