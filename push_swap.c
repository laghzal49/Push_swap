/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:27 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/02 23:22:00 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void    init_stack_a(Node **a, char **argv, int argc)
{
    long    nbr;
    char    **args;
    char    **tmp_args; // Pointer to the start of the array (for cleanup)
    int     split_flag; // 1 if ft_split was used, 0 otherwise

    // 1. Handle Input Cases
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args || !args[0]) // Check for NULL or empty result from ft_split
        {
            if (args)
                free(args); // Free the outer array if split was empty
            if (argv[1] && argv[1][0] == '\0') // Check for empty string input
                return;
            write(2, "Error\n", 6); 
            exit(1);
        }
        tmp_args = args;
        split_flag = 1;
    }
    else
    {
        // Start processing from argv[1] (skip program name)
        args = argv + 1;
        tmp_args = argv; // Not strictly needed, but kept for clarity on original argv
        split_flag = 0;
    }
    
    // 2. Loop, Validate, and Build Stack
    while (*args)
    {
        // a. Syntax Check (checks for non-digits, multiple signs, etc.)
        if (error_syntax(*args))
            free_errors(a, tmp_args, split_flag);

        // b. Conversion to long for Overflow Check
        nbr = ft_atol(*args);
        
        // c. Range Check (must fit within INT_MIN and INT_MAX)
        if (nbr > INT_MAX || nbr < INT_MIN)
            free_errors(a, tmp_args, split_flag);

        // d. Duplicate Check
        if (error_duplicate(*a, (int)nbr))
            free_errors(a, tmp_args, split_flag);

        // e. Append Node to Stack A
        append_node(a, (int)nbr);
        
        args++;
    }

    // 3. Final Cleanup for ft_split
    // If ft_split was used, the resulting array must be freed.
    if (split_flag)
        free_matrix(tmp_args);
}

int main(int ac, char **av)
{
	Node *stack_a;
	Node *stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	init_stack_a(&stack_a, av, ac);
	index_stack(stack_a);
	size = ft_lstsize(stack_a);
	if (is_sorted(stack_a))
		return 0;
	else if (size <= 5)
		simple_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return 0;
}