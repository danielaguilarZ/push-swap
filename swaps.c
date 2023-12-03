#include "push_swap.h"

void ft_swap_a(t_node **stack)
{
    int temp;
    t_node *first;
    t_node *second;

    if(*stack && (*stack)->next)
    {
        first = *stack;
        second = (*stack)->next;
    }
    temp = first->nb;
    first->nb = second->nb;
    second->nb= temp;
}