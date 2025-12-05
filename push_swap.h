/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:23 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/05 13:43:55 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				x;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void	init_stack_a(t_node **a, char **argv, int argc);
void	free_errors(t_node **a, char **args, int spl);
long	ft_atol(const char *str);
void	append_node(t_node **stack, int n);
void	free_stack(t_node **stack);
int		ft_lstsize(t_node *head);
int		error_syntax(char *str_n);
int		error_duplicate(t_node *a, int n);
void	free_matrix(char **argv);
void	index_stack(t_node *stack);
int		is_sorted(t_node *stack);
void	simple_sort(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);
char	**ft_split(char const *s, char c);

#endif