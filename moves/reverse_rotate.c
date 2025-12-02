#include "push_swap.h"

static void	reverse(Node **stack)
{
	Node	*last;
	
	if (*stack || !(*stack)->next)
		return ;
	last = stack;
	while (last->next)
		last = last->next;
	last->next = stack;
	last->prev = NULL;
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