#include "push_swap.h"

void ft_sort_three(t_stack **A)
{
    t_stack *max_node;

    max_node = ft_stack_max(*A);
    if (max_node == *A)
        ft_ra(A, true);
    else if ((*A)->next == max_node)
        ft_rra(A, true);
    if ((*A)->nb > (*A)->next->nb)
        ft_sa(A, true);
}


