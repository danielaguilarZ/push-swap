/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:29 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/20 18:21:59 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap Operation

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_sa(t_stack **A, bool print)
{
	ft_swap(A);
	if (print == true)
		printf("sa\n");
}

void	ft_sb(t_stack **B, bool print)
{
	ft_swap(B);
	if (print == true)
		printf("sb\n");
}

void	ft_ss(t_stack **A, t_stack **B, bool print)
{
	ft_swap(A);
	ft_swap(B);
	if (print == true)
		printf("ss\n");
}
