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
    t_stack *newNode = ft_new_stack(nb);

    if (newNode)
    {
        t_stack *temp = *stack;

        if (temp)
        {
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
        else
            *stack = newNode;
    }
}



void ft_print_stacks(t_stack *A, t_stack *B)
{
    printf("\n");
    if (A == NULL)
        printf("Stack A: \n");
    else
    {
        while (A != NULL)
        {
            printf("Stack A: %ld\n", A->nb);
            A = A->next;
        }
    }

    printf("\n");

    if (B == NULL)
        printf("Stack B: \n");
    else
    {
        while (B != NULL)
        {
            printf("Stack B: %ld\n", B->nb);
            B = B->next;
        }
    }
}

// void ft_swap_a(t_stack **stack)
// {
//     int temp;
//     t_stack *first;
//     t_stack *second;

//     if(*stack && (*stack)->next)
//     {
//         first = *stack;
//         second = (*stack)->next;
//     }
//     temp = first->nb;
//     first->nb = second->nb;
//     second->nb= temp;

// }

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
void ft_push_b(t_stack **A, t_stack **B)
    }
    else
        printf("Stack B: empty\n");
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

    ft_push_b(&A, &B);

    ft_print_stacks(A, B);

    ft_push_b(&A, &B);

    ft_print_stacks(A, B);

    ft_swap_ab(&A, &B);

    ft_print_stacks(A, B);

    ft_push_a(&B, &A);

    ft_print_stacks(A, B);
}