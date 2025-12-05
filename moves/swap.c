/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:41 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/04 13:15:23 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node *head)
{
	int	tmp_x;
	int	tmp_i;

	if (!head || !head->next)
		return ;
	tmp_x = head->x;
	head->x = head->next->x;
	head->next->x = tmp_x;
	tmp_i = head->index;
	head->index = head->next->index;
	head->next->index = tmp_i;
}

void	sa(t_node **a, int print)
{
	swap(*a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int print)
{
	swap(*b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int print)
{
	swap(*a);
	swap(*b);
	if (print)
		write(1, "ss\n", 3);
}
