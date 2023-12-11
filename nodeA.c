/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeA.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:34 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/11 17:40:46 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_target_a(t_stack *A, t_stack *B)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_index;

	while (A)
	{
		best_index = LONG_MIN;
		current_b = B;
		while (current_b)
		{
			if (current_b->nb < A->nb && current_b->nb > best_index)
			{
				best_index = current_b->nb;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			A->target_node = ft_stack_max(B);
		else
			A->target_node = target_node;
		A = A->next;
	}
}

static void	ft_cost_push_a(t_stack *A, t_stack *B)
{
	int	size_stack_a;
	int	size_stack_b;

	size_stack_a = ft_stack_size(A);
	size_stack_b = ft_stack_size(B);
	while (A)
	{
		A->push_cost = A->index;
		if (!(A->above_median))
			A->push_cost = size_stack_a - (A->index);
		if (A->target_node->above_median)
			A->push_cost += A->target_node->index;
		else
			A->push_cost += size_stack_b - (A->target_node->index);
		A = A->next;
	}
}

void	ft_nodes_a(t_stack *A, t_stack *B)
{
	ft_current_index(A);
	ft_current_index(B);
	ft_set_target_a(A, B);
	ft_cost_push_a(A, B);
	ft_optimal(A);
}
