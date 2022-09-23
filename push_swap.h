/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:56:11 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:47:48 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	struct s_stack		*next;
	struct s_stack		*prev;
	int					value;
	int					index;
	int					flag;
}	t_stack;

typedef struct s_all
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			min_a;
	int			min;
	int			med;
	int			max;
	int			len_a;
	int			len_b;
}	t_all;
int		main(int argc, char **argv);
//parser

t_all	*parser(char **argv);

char	**make_array(char **argv);
void	ft_valid(char **arr);
void	ft_valid_next(long long temp, char **arr);
void	ft_error(void);
int		ft_duplicate(char **arr);

t_all	*struct_init(char	**arr);
void	arr_to_stack(char **arr, t_all *all);
void	bubblesort(int *unsorted, int *sorted, int len, t_all *all);
void	create_stack(t_all *all, int *sorted, int *unsorted, int len);
t_stack	*create_list(int value, int index);
void	add_list(t_stack **stack_a, t_stack *new);

void	free_array(char	**arr);

void	ft_valid(char **arr);
void	ft_error(void);
int		ft_duplicate(char **arr);

//sorting

void	sort(t_all *all);
int		is_sorted(t_all *all);

void	simple_a(t_all *all);
void	sort_5_a(t_all *all);
void	sort_4_a(t_all *all);
void	sort_3_a(t_all *all);

void	do_first(t_all *all);
void	med_min_max_a(t_all *all);
void	sorted_go_a(t_all *all);

void	go_b_to_a(t_all *all);
void	med_min_max_b(t_all *all);
int		find_next_b(t_all *all);

void	simple_b(t_all *all);
void	simple_b_next(t_all *all, int f);
void	sort_3_b(t_all *all);

void	sort_a(t_all *all, int a, int flag, int index);
void	sort_a_next(t_all *all, int f);
void	sort_in_b_for_a(t_all *all);
void	ra_a(t_all *all);

void	go_a_to_b(t_all *all);
void	find_next_a(t_all *all);

void	free_stacks(t_all *all);

//actions

void	sa(t_all *all, int f);
void	sb(t_all *all, int f);
void	ss(t_all *all, int f);

void	pa(t_all *all, int f);
void	do_pa(t_all *all);
void	pb(t_all *all, int f);
void	do_pb(t_all *all);

void	ra(t_all *all, int f);
void	rb(t_all *all, int f);
void	rr(t_all *all, int f);

void	rra(t_all *all, int f);
void	rrb(t_all *all, int f);
void	rrr(t_all *all, int f);

//gnl
char	*get_next_line(int fd);
char	*ft_readline(int fd, char *remain, char *buffer);
char	*ft_findend(char *str);
char	*gnl_strjoin(char *remain, char *buffer);
int		gnl_strlen(const char *str);
char	*ft_getline(char *remain);
char	*ft_remainnew(char *remain);

#endif