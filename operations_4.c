#include "push_swap.h"


// Push Operation

void ft_push(t_stack **src, t_stack **dst)
{
    if (*src != NULL)
    {
        t_stack *temp;

        temp = *src;
        *src = (*src)->next;
        temp->next = *dst;
        *dst = temp;
    }
}

void ft_pb(t_stack **A, t_stack **B, bool print)
{
    ft_push(A, B);
    if(print == true)
        printf("pb\n");
}

void ft_pa(t_stack **B, t_stack **A, bool print)
{
    ft_push(B, A);
    if(print == true)
        printf("pa\n");
}