/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:10 by daguilar          #+#    #+#             */
/*   Updated: 2023/11/29 17:36:36 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			nb;
	long			index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void ft_swap(t_stack **stack);
void ft_sa(t_stack **A, bool print);
void ft_sb(t_stack **B, bool print);
void ft_ss(t_stack **A , t_stack **B, bool print);

void ft_push(t_stack **src, t_stack **dst);
void ft_pb(t_stack **A, t_stack **B, bool print);
void ft_pa(t_stack **B, t_stack **A, bool print);

void ft_rerverse_rotation(t_stack **stack);
void ft_rra(t_stack **A, bool print);
void ft_rrb(t_stack **B, bool print);
void f_rrr(t_stack **A, t_stack **B, bool print);

void	ft_rotation(t_stack **stack);
void ft_ra(t_stack **A, bool print);
void ft_rb(t_stack **B, bool print);
void ft_rr(t_stack **A, t_stack **B, bool print);

void ft_create_stack_a(t_stack **A, char **argv);
void ft_print_stacks(t_stack *A, t_stack *B);


t_stack	*ft_stack_last(t_stack *stack);
int	ft_stack_size(t_stack *stack);
t_stack	*ft_stack_min(t_stack *stack);
t_stack	*ft_stack_max(t_stack *stack);

int ft_e_syntax(char *str);
int ft_e_duplicated(t_stack *A, int n);
void ft_free_stack(t_stack **stack);
void ft_free_errors(t_stack **A);


#endif
