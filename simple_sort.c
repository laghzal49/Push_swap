#include "push_swap.h"

int	is_sorted(Node *stack)
{
	while (stack->next)
	{
		if (stack->x > stack->next->x)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void	sort_three(Node **a)
{
	Node *head;
	int max;

	max = head->x;
	head = *a;
	if (head->next->x > max)
		max = head->next->x;
	if (head->next->next->x > max)
		max = head->next->next->x;
	
	if ((*a)->x == max)
		ra(a, 1);
	if ((*a)->next->x == max)
		raa(a, 1);
	if ((*a)->x > (*a)->next->x)
		sa(a, 1);
}
static void	move_min_to_top(Node **a)
{
	Node	*head;
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

static void	sort_five(Node **a, Node **b)
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
void    simple_sort(Node **a,Node **b);
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->x > (*a)->next->x)
			swap(a, 1);
	}
	else if (size == 3)
		sort_three(a);
	else
		sort_five(a);
}