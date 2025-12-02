#include "push_swap.h"

void	swap(Node *head)
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

void	sa(Node **a, int print)
{
	swap(*a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(Node **b, int print)
{
	swap(*b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(Node **a, Node **b, int print)
{
	swap(*a);
	swap(*b);
	if (print)
		write(1, "ss\n", 3);
}