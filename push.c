/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:34:18 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/11 17:34:19 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push Operation

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (*src != NULL)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dst;
		*dst = temp;
	}
}

void	ft_pb(t_stack **A, t_stack **B, bool print)
{
	ft_push(A, B);
	if (print == true)
		printf("pb\n");
}

void	ft_pa(t_stack **B, t_stack **A, bool print)
{
	ft_push(B, A);
	if (print == true)
		printf("pa\n");
}
