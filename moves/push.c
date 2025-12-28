/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:49 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/04 13:15:08 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*push_node;

	if (!src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		(*dest)->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_node **a, t_node **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}
