#include "push_swap.h"

static void	push(Node **src, Node **dest)
{
	Node	*push_node;

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

void	pa(Node **a, Node **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(Node **a, Node **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}
