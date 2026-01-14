/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:38 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/04 14:22:00 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_stack(t_node *stack)
{
	t_node	*curr;
	t_node	*check;	
	int		c;

	curr = stack;
	while (curr)
	{
		check = stack;
		c = 0;
		while (check)
		{
			if (check->x < curr->x)
				c++;
			check = check->next;
		}
		curr->index = c;
		curr = curr->next;
	}
}

static int	calculate_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	process_bit(t_node **a, t_node **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			pb(a, b, 1);
		else
			ra(a, 1);
		i++;
	}
	while (*b)
		pa(a, b, 1);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	bit;
	int	size;
	int	max_bits;

	if (!a || !*a || is_sorted(*a))
		return ;
	index_stack(*a);
	size = ft_lstsize(*a);
	max_bits = calculate_max_bits(size);
	bit = 0;
	while (bit < max_bits && !is_sorted(*a))
	{
		process_bit(a, b, bit, size);
		bit++;
	}
}
