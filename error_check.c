#include "push_swap.h"

void	free_errors(Node **a, char **args, int spl)
{
	free_stack(a);
	if (spl)
		free_matrix(args);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str_n)
{
	if (!(*str_n))
		return (1);
	if (*str_n == '+' || *str_n == '-')
		str_n++;
	if (!(*str_n))
		return (1);
	while (*str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
		str_n++;
	}
	return (0);
}

int	error_duplicate(Node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->x == n)
			return (1);
			a = a->next;
	}
	return (0);
}