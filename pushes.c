#include "push_swap.h"

void ft_push_b(t_stack **A, t_stack **B)
{
    if (*A != NULL)
    {
        t_stack *temp;

        temp = *A;
        *A = (*A)->next;
        temp->next = *B;
        *B = temp;
    }
    else
        printf("Stack A: empty\n");
}

void ft_push_a(t_stack **B, t_stack **A)
{
    if (*B != NULL)
    {
        t_stack *temp;

        temp = *B;
        *B = (*B)->next;
        temp->next = *A;
        *A = temp;
    }
    else
        printf("Stack B: empty\n");
}