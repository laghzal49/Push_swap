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
		write(1, "ra\n", 1);
}

void	rb(Node **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 1);
}

void	rr(Node **a, Node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}