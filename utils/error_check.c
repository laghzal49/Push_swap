/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:36 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/04 13:16:14 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_errors(t_node **a, char **args, int spl)
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

int	error_duplicate(t_node *a, int n)
{
	while (a)
	{
		if (a->x == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_matrix(char **argv)
{
	char	**tmp;

	tmp = argv;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(argv);
}
