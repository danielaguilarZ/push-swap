#include "push_swap.h"


// Reverse rotation

void ft_rerverse_rotation(t_stack **stack)
{
    if (*stack && (*stack)->next)
    {
        t_stack *last;
        t_stack *prev_to_last;

        prev_to_last = NULL;
        last = *stack;
        while (last->next != NULL)
        {
            prev_to_last = last;
            last = last->next;
        }

        last->next = *stack;
        *stack = last;
        prev_to_last->next = NULL;
    }
}

void ft_rra(t_stack **A, bool print)
{
    ft_rerverse_rotation(A);
    if(print == true)
        printf("rra\n");
}

void ft_rrb(t_stack **B, bool print)
{
    ft_rerverse_rotation(B);
    if(print == true)
        printf("rrb\n");
}

void ft_rrr(t_stack **A, t_stack **B, bool print)
{
    ft_rerverse_rotation(A);
    ft_rerverse_rotation(B);
    if(print == true)
        printf("rrr\n");
}