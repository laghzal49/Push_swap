/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:07:23 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/12/02 23:41:49 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
typedef struct s_node
{
    int             x;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
} Node;

// *** Initialization & Parsing (init_stack.c) ***
void    init_stack_a(Node **a, char **argv, int argc);
void    free_errors(Node **a, char **args, int spl);

// *** Utils (stack_utils.c) ***
long    ft_atol(const char *str);
void    append_node(Node **stack, int n);
void    free_stack(Node **stack);
int     ft_lstsize(Node *head);
int     error_syntax(char *str_n);
int     error_duplicate(Node *a, int n);
void    free_matrix(char **argv);

// *** Indexing (index.c) ***
void    index_stack(Node *stack);

// *** Sorting Algorithms (sort.c - Coming Soon) ***
int     is_sorted(Node *stack);
void    simple_sort(Node **a,Node **b);
void    radix_sort(Node **a, Node **b);

// *** Operations ***
// push.c
void    pa(Node **a, Node **b, int print);
void    pb(Node **a, Node **b, int print);

// swap.c
void    sa(Node **a, int print);
void    sb(Node **b, int print);
void    ss(Node **a, Node **b, int print);

// rotate.c
void    ra(Node **a, int print);
void    rb(Node **b, int print);
void    rr(Node **a, Node **b, int print);

// reverse_rotate.c
void    rra(Node **a, int print);
void    rrb(Node **b, int print);
void    rrr(Node **a, Node **b, int print);

// *** Libft Dependencies (If you don't include "libft.h") ***
char    **ft_split(char const *s, char c);

#endif