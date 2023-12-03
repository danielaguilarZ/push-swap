#include "push_swap.h"

t_stack *ft_new_stack(int content)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof (t_stack));
    if(!new)
        exit(1);
    new->nb = content;
    new->next = NULL;
    return (new);
}

void ft_add(t_stack **stack, int nb)
{
    t_stack *newNode;
    
    newNode = ft_new_stack(nb);
    if (newNode)
    {
        newNode->next = *stack;
        *stack = newNode;
    }
}

void ft_print_stacks(t_stack *A, t_stack *B)
{
    if (A == NULL || A->next == NULL)
        printf("Stack A: empty\n");
    else
    {          
        while (A)
        {
            printf("Stack A: %d\n", A->nb);
            A = A->next;
        }
    }
    printf("\n");
    if (B == NULL || B->next == NULL)
        printf("Stack B: empty\n");
    else
    {
        while (B)
        {
            printf("Stack B: %d\n", B->nb);
            B = B->next;
        }
    }
}

int main(int argc, char **argv)
{
    t_stack *A;
    t_stack *B;
    int i;
    int nb;

    i = 1;
    A = NULL;
    B = NULL;

    if (argc < 2)
        exit(1);
    while (i < argc)
    {
        nb = atoi(argv[i]);
        ft_add(&A, nb);
        i++;
    }
    
    ft_print_stacks(A, B);
}