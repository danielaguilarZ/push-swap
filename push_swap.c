/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:07 by daguilar          #+#    #+#             */
/*   Updated: 2023/11/29 18:25:52 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *A;
    t_stack *B;
    int i;
    int nb;

    i = 1;
    A = NULL;
    B = NULL;

    ft_create_stack_a(&A, argv + 1);

    ft_print_stacks(A, B);
    printf("\n");

    ft_ss(&A, &B, true);
    ft_pb(&A, &B, true);
    ft_pb(&A, &B, true);
    ft_pb(&A, &B, true);
    ft_ss(&A, &B, true);

    ft_print_stacks(A, B);

}