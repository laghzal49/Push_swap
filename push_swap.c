#include <stdlib.h>
#include "push_swap.h"

void	init_stack_a(Node** a, char **argv, int argc)
{
	long		nbr;
	char	**args;
	int				i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		
	}
}
int main(int ac, char **av)
{
	Node *stack_a;
	Node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	init_stack_a(&stack_a, av, ac);
	
	//algo!!!!!!!!!!!!!
}