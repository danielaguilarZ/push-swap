/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:10 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/14 19:55:55 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "include/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			nb;
	long			index;
	int				push_cost;
	bool			above_median;
	bool			optimal;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Push0

void				ft_push(t_stack **src, t_stack **dst);
void				ft_pb(t_stack **A, t_stack **B, bool print);
void				ft_pa(t_stack **B, t_stack **A, bool print);

// Swap

void				ft_swap(t_stack **stack);
void				ft_sa(t_stack **A, bool print);
void				ft_sb(t_stack **B, bool print);
void				ft_ss(t_stack **A, t_stack **B, bool print);

// Rotation

void				ft_rotation(t_stack **stack);
void				ft_ra(t_stack **A, bool print);
void				ft_rb(t_stack **B, bool print);
void				ft_rr(t_stack **A, t_stack **B, bool print);
void				ft_rr_both(t_stack **A, t_stack **B, t_stack *optimal_node);

// Reverse rotation

void				ft_rerverse_rotation(t_stack **stack);
void				ft_rra(t_stack **A, bool print);
void				ft_rrb(t_stack **B, bool print);
void				ft_rrr(t_stack **A, t_stack **B, bool print);
void				ft_rrr_both(t_stack **A, t_stack **B,
						t_stack *optimal_node);

// Libft utils

long				ft_atoi_ps(const char *s);
char				**ft_split_ps(char *s, char c);

// Stack utils

t_stack				*ft_stack_last(t_stack *stack);
t_stack				*ft_stack_min(t_stack *stack);
t_stack				*ft_stack_max(t_stack *stack);
int					ft_stack_size(t_stack *stack);
bool				ft_stack_sorted(t_stack *stack);

void				ft_create_stack_a(t_stack **A, char **argv);
void				ft_print_stacks(t_stack *A, t_stack *B);

// Node utils

void				ft_ready_to_push(t_stack **stack, t_stack *top_node,
						char A_or_B);
void				ft_optimal(t_stack *stack);
void				ft_current_index(t_stack *stack);
t_stack				*ft_get_optimal(t_stack *stack);

// Nodes

void				ft_nodes_a(t_stack *A, t_stack *B);
void				ft_nodes_b(t_stack *A, t_stack *B);

// Errors

int					ft_e_syntax(char *str);
int					ft_e_duplicated(t_stack *A, int n);
void				ft_free_stack(t_stack **stack);
void				ft_free_errors(t_stack **A);

// Sort

void				ft_sort_three(t_stack **A);
void				ft_sort_all(t_stack **A, t_stack **B);

void	ft_operation_checker(t_stack *a, t_stack *b, char *operation);

#endif
