/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:57:07 by jlenna            #+#    #+#             */
/*   Updated: 2022/03/26 20:16:20 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_all *all)
{
	if (is_sorted(all))
	{
		free_stacks(all);
		exit(0);
	}
	if (all->len_a < 6)
	{
		simple_a(all);
		free_stacks(all);
	}
	do_first(all);
	while (!(is_sorted(all) && all->len_b == 0))
	{
		if (all->len_b >= 6)
			go_b_to_a(all);
		else if (all->len_b < 6 && all->len_b > 0)
			simple_b(all);
		if (all->len_b == 0)
		{
			sort_a(all, 0, 0, 0);
			go_a_to_b(all);
		}
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc > 1)
	{
		all = parser(argv);
		sort(all);
		free_stacks(all);
	}
	return (0);
}
