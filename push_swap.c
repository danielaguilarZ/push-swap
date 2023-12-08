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

    A = NULL;
    B = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split_ps(argv[1], ' ');
    ft_create_stack_a(&A, argv + 1);
    // ft_print_stacks(A, B);
    printf("\n");
    if (ft_stack_sorted(A) == false)
    {
        if (ft_stack_size(A) == 2)
            ft_sa(&A, true);
        else if (ft_stack_size(A) == 3)
            ft_sort_three(&A);
        else
            ft_sort_all(&A, &B);     
    }
    printf("\n");
    // ft_print_stacks(A, B);

    ft_free_stack(&A);
}