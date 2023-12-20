/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:47:18 by daguilar          #+#    #+#             */
/*   Updated: 2023/12/20 19:00:43 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_print_stacks(const t_stack *A, const t_stack *B)
{
    printf("\nStack A:\n");
    const t_stack *tempA = A;
    while (tempA != NULL)
    {
        printf("%ld\n", tempA->nb);
        tempA = tempA->next;
    }

    printf("\nStack B:\n");
    const t_stack *tempB = B;
    while (tempB != NULL)
    {
        printf("%ld\n", tempB->nb);
        tempB = tempB->next;
    }
}

bool	ft_operation_checker(t_stack **a, t_stack **b, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 4) == 0)
		ft_sa(a, false);
	else if (ft_strncmp(operation, "sb\n", 4) == 0)
		ft_sb(b, false);
	else if (ft_strncmp(operation, "ss\n", 4) == 0)
		ft_ss(a, b, false);
	else if (ft_strncmp(operation, "ra\n", 4) == 0)
		ft_ra(a, false);
	else if (ft_strncmp(operation, "rb\n", 4) == 0)
		ft_rb(b, false);
	else if (ft_strncmp(operation, "rr\n", 4) == 0)
		ft_rr(a, b, false);
	else if (ft_strncmp(operation, "rra\n", 5) == 0)
		ft_rra(a, false);
	else if (ft_strncmp(operation, "rrb\n", 5) == 0)
		ft_rrb(b, false);
	else if (ft_strncmp(operation, "rrr\n", 5) == 0)
		ft_rrr(a, b, false);
	else if (ft_strncmp(operation, "pa\n", 4) == 0)
		ft_pa(b, a, false);
	else if (ft_strncmp(operation, "pb\n", 4) == 0)
		ft_pb(a, b, false);
	else
		return((void)printf("Error\n"), true);
	return(false);
}


int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char *operation;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split_ps(argv[1], ' ');
	ft_create_stack_a(&a, argv + 1);
	while ((operation = get_next_line(0)) != NULL)
	{
		if (ft_strncmp(operation, "Error\n", 7) == 0)
			printf("Error");
		else
			if (ft_operation_checker(&a, &b, operation) == true)
				return (ft_free_stack(&a), ft_free_stack(&b), 1);
	}
	if (ft_stack_sorted(a) == true && !b)
		printf("OK");
	else
		printf("KO");
	ft_print_stacks(a, b);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
