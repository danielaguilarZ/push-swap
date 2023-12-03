#include "push_swap.h"

void push_b(t_stackA **stackA, t_stackB **stackB)
{
    if (*stackA != NULL)
    {
        t_stack A *temp;

        temp = *stackA;
        *stackA = (*stackA)->next;
        temp->next = *stackB;
        *stackB = temp;
    }
    else
        printf("Stack A: empty\n");
}