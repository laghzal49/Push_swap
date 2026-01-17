/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:27 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/04 14:01:33 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	fill_stack_loop(t_node **a, char **args, char **tmp_args, int spl_flag)
{
	long	nbr;

	while (*args)
	{
		if (error_syntax(*args))
			free_errors(a, tmp_args, spl_flag);
		nbr = ft_atol(*args);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(a, tmp_args, spl_flag);
		if (error_duplicate(*a, (int)nbr))
			free_errors(a, tmp_args, spl_flag);
		append_node(a, (int)nbr);
		args++;
	}
	if (spl_flag)
		free_matrix(tmp_args);
}

void	init_stack_a(t_node **a, char **argv, int argc)
{
	char	**args;
	char	**tmp_args;
	int		split_flag;

	split_flag = 0;
	tmp_args = argv + 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			if (args)
				free(args);
			if (argv[1] && argv[1][0] == '\0')
				return ;
			write(2, "Error\n", 6);
			exit(1);
		}
		tmp_args = args;
		split_flag = 1;
	}
	else
		args = argv + 1;
	fill_stack_loop(a, args, tmp_args, split_flag);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	init_stack_a(&stack_a, av, ac);
	index_stack(stack_a);
	size = ft_lstsize(stack_a);
	if (is_sorted(stack_a))
		return (0);
	else if (size <= 5)
		simple_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
