/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:56:30 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:29:30 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cmd_check(t_all *all, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(all, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(all, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(all, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(all, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(all, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(all, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(all, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(all, 1);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(all, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(all, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(all, 0);
	else
		ft_error();
}

static void	checker(t_all *all)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		cmd_check(all, line);
	}
	if (is_sorted(all))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

char	**make_array(char **argv)
{
	int		i;
	char	*line;
	char	*temp;
	char	**arr;

	line = ft_strdup(argv[1]);
	i = 2;
	while (argv[i])
	{
		temp = line;
		line = ft_strjoin(line, " ");
		free(temp);
		temp = line;
		line = ft_strjoin(line, argv[i]);
		free(temp);
		i++;
	}
	arr = ft_split(line, ' ');
	free(line);
	return (arr);
}

t_all	*parser(char **argv)
{
	t_all	*all;
	char	**arr;

	arr = make_array(argv);
	ft_valid(arr);
	all = struct_init(arr);
	arr_to_stack(arr, all);
	free_array(arr);
	return (all);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc > 1)
	{
		all = parser(argv);
		checker(all);
		free_stacks(all);
	}
	return (0);
}
