#include "push_swap.h"

static void ft_set_target_b(t_stack *A, t_stack *B)
{
    t_stack *currentA;
    t_stack *target_node;
    long    best_index;

    while(B)
    {
        best_index = LONG_MAX;
        currentA = A;
        while(currentA)
        {
            if (currentA->nb > B->nb && currentA->nb < best_index)
            {
                best_index = currentA->nb;
                target_node = currentA;
            }
            currentA = currentA->next;
        }
        if(best_index == LONG_MAX)
            B->target_node = ft_stack_min(A);
        else
            B->target_node = target_node;
        B = B->next;
    }
}

void ft_nodes_B(t_stack *A, t_stack *B)
{
    ft_current_index(A);
    ft_current_index(B);
    ft_set_target_b(A, B);
}