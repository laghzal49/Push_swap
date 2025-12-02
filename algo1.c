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
		c = 1;
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