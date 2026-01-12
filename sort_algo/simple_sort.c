/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:26:25 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/04 13:15:35 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->x > stack->next->x)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_node **a)
{
	t_node	*head;

	head = *a;
	if (is_sorted(*a))
		return ;
	if (head->x > head->next->x && head->x > head->next->next->x)
		ra(a, 1);
	else if (head->next->x > head->x && head->next->x > head->next->next->x)
		rra(a, 1);
	if ((*a)->x > (*a)->next->x)
		sa(a, 1);
}

static void	move_min_to_top(t_node **a)
{
	t_node	*head;
	int		min;
	int		min_pos;
	int		i;

	head = *a;
	min = head->x;
	min_pos = 0;
	i = 0;
	while (head)
	{
		if (head->x < min)
		{
			min = head->x;
			min_pos = i;
		}
		head = head->next;
		i++;
	}
	if (min_pos < ft_lstsize(*a) / 2)
		while ((*a)->x != min)
			ra(a, 1);
	else
		while ((*a)->x != min)
			rra(a, 1);
}

static void	sort_five(t_node **a, t_node **b)
{
	while (ft_lstsize(*a) > 3)
	{
		move_min_to_top(a);
		pb(a, b, 1);
	}
	sort_three(a);
	while (*b)
		pa(a, b, 1);
}

void	simple_sort(t_node **a, t_node **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->x > (*a)->next->x)
			sa(a, 1);
	}
	else if (size == 3)
		sort_three(a);
	else if (size < 6)
		sort_five(a, b);
}
