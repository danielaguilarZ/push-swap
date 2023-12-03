#include "push_swap.h"

void ft_reverse_rotate_a(t_node **stack)
{
    if (*stack && (*stack)->next)
    {
        t_node *last;
        t_node *prev_to_last;

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