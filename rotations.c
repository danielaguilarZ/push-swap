#include "push_swap.h"

void ft_rotate_a(t_node **stack)
{
    t_node *last;
    t_node *second;

    if (*stack && (*stack)->next)
    {
        last = *stack;
        second = (*stack)->next;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = *stack;
    *stack = second;
    last->next->next = NULL;
}