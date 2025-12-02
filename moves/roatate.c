/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roatate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:43 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/02 23:45:47 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(Node **stack)
{
	Node	*last;
	Node	*first;

	if (!(*stack) || !(*stack)->next)
		return;
	last = *stack;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(Node **a, int print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(Node **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(Node **a, Node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}