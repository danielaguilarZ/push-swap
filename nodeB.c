/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeB.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:32 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/11 17:38:31 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_target_b(t_stack *A, t_stack *B)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_index;

	while (B)
	{
		best_index = LONG_MAX;
		current_a = A;
		while (current_a)
		{
			if (current_a->nb > B->nb && current_a->nb < best_index)
			{
				best_index = current_a->nb;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			B->target_node = ft_stack_min(A);
		else
			B->target_node = target_node;
		B = B->next;
	}
}

void	ft_nodes_b(t_stack *A, t_stack *B)
{
	ft_current_index(A);
	ft_current_index(B);
	ft_set_target_b(A, B);
}
