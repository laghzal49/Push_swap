/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:38 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/02 23:30:06 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(Node *stack)
{
	Node 	*curr;
	Node 	*check;	
	int			c;

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

void	radix_sort(Node** a, Node** b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_lstsize(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				 pb(a, b, 1);
			else
				ra(a, 1);
			j++;
		}
		while (*b)
			pa(a, b, 1);
		i++;
	}
}