#include "push_swap.h"

void  ft_current_index(t_stack *stack)
{
    int i;
    int mid;

    i = 0;
    if (!stack)
        return;
    mid = ft_stack_size(stack) / 2;
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

static void ft_set_target_a(t_stack *A, t_stack *B)
{
    t_stack *currentB;
    t_stack *target;
    long    best_index;

    while(A)
    {
        best_index = LONG_MIN;
        currentB = b;
        while(currentB)
        {
            if (currentB->nb < A->nb && currentB->nb > best_index)
            {
                best_index = currentB->nb;
                target = currentB;
            }
            currentB = currentB->next;
        }
        if(best_index == LONG_MIN)
            A->target_node = ft_stack_max(B);
        else
            A->target_node = target;
        A = A->next;
    }
}
void ft_nodes_A(t_stack *A, t_stack *B)
{
    ft_current_index(A);
    ft_current_index(B);
    ft_set_target_a(a, b);

}