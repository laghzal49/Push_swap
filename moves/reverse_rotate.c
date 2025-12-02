/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:46 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/02 23:47:17 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse(Node **stack)
{
    Node    *last;
    Node    *second_last;

    if (!*stack || !(*stack)->next)
        return ;
    last = *stack;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    if (second_last)
        second_last->next = NULL;
    last->prev = NULL; 
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}

void	rra(Node **a, int print)
{
	reverse(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(Node **b, int print)
{
	reverse(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(Node **a, Node **b, int print)
{
	reverse(a);
	reverse(b);
	if (print)
		write(1, "rrr\n", 4);
}