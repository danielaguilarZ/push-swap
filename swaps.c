#include "push_swap.h"

void ft_swap_a(t_stack **A)
{
    int temp;
    t_stack *first;
    t_stack *second;

    if(*A && (*A)->next)
    {
        first = *A;
        second = (*A)->next;
    }
    temp = first->nb;
    first->nb = second->nb;
    second->nb= temp;
}

void ft_swap_b(t_stack **B)
{
    int temp;
    t_stack *first;
    t_stack *second;

    if(*B && (*B)->next)
    {
        first = *B;
        second = (*B)->next;
    }
    temp = first->nb;
    first->nb = second->nb;
    second->nb= temp;
}

void ft_swap_ab(t_stack **A , t_stack **B)
{
    int tempA;
    int tempB;
    t_stack *first;
    t_stack *second;

    if(*A && (*A)->next)
    {
        first = *A;
        second = (*A)->next;
    }
    tempA= first->nb;
    first->nb = second->nb;
    second->nb= tempA;

    if(*B && (*B)->next)
    {
        first = *B;
        second = (*B)->next;
    }
    tempB = first->nb;
    first->nb = second->nb;
    second->nb= tempB;
}