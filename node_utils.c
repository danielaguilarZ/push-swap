/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:37 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/11 17:38:42 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

t_stack	*ft_get_optimal(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->optimal)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_optimal(t_stack *stack)
{
	long	optimal_value;
	t_stack	*optimal_node;

	if (!stack)
		return ;
	optimal_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < optimal_value)
		{
			optimal_value = stack->push_cost;
			optimal_node = stack;
		}
		stack = stack->next;
	}
	optimal_node->optimal = true;
}

void	ft_ready_to_push(t_stack **stack, t_stack *top_node, char A_or_B)
{
	while (*stack != top_node)
	{
		if (A_or_B == 'A')
		{
			if (top_node->above_median)
				ft_ra(stack, true);
			else
				ft_rra(stack, true);
		}
		else if (A_or_B == 'B')
		{
			if (top_node->above_median)
				ft_rb(stack, true);
			else
				ft_rrb(stack, true);
		}
	}
}
