/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:07 by daguilar          #+#    #+#             */
/*   Updated: 2023/11/29 18:25:52 by daguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stackA *ft_create_stack_a(int nb)
{
    t_stackA *newNode;

    newNode = (t_stackA *)malloc(sizeof(t_stackA));
    if (newNode)
    {
        newNode->nb = nb;
        newNode->next = NULL;
    }
    return (newNode);
}

t_stackB *ft_create_stack_b()
{
    t_stackB *stack_b = (t_stackB *)malloc(sizeof(t_stackB));
    if(!stack_b)
        return (NULL);
    stack_b->next = NULL;
    return (stack_b);
}

void ft_add(t_stackA **stack, int nb)
{
    t_stackA *newNode;
    
    newNode = ft_create_stack_a(nb);
    if (newNode)
    {
        newNode->next = *stack;
        *stack = newNode;
    }
}

void ft_swap_a(t_stackA **stack)
{
    int temp;
    t_stackA *first;
    t_stackA *second;

    if(*stack && (*stack)->next)
    {
        first = *stack;
        second = (*stack)->next;
    }
    temp = first->nb;
    first->nb = second->nb;
    second->nb= temp;
}

void ft_rotate_a(t_stackA **stack)
{
    t_stackA *last;
    t_stackA *second;

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

void ft_reverse_rotate_a(t_stackA **stack)
{
    if (*stack && (*stack)->next)
    {
        t_stackA *last;
        t_stackA *prev_to_last;

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


void ft_print_stack(t_stackA *stackA, t_stackB *stackB, StackType type)
{
    if (type == STACK_A)
    {
        if (stackA == NULL || stackA->next == NULL)
            printf("Stack A: empty\n");
        else
            while (stackA)
            {
                printf("Stack A: %d\n", stackA->nb);
                stackA = stackA->next;
            }
    }
    else if (type == STACK_B)
    {
        if (stackB == NULL || stackB->next == NULL)
            printf("Stack B: empty\n");
        else
            while (stackB)
            {
                printf("Stack B: %d\n", stackB->nb);
                stackB = stackB->next;
            }
    }
    else
    {
        printf("Invalid stack type\n");
    }
}

void push_b(t_stackA **stackA, t_stackB **stackB)
{
    if (*stackA != NULL)
    {
        t_stackA *tempA;
        t_stackB *tempB;
        tempB = (t_stackB *)malloc(sizeof(t_stackB));

        tempA = *stackA;
        *stackA = (*stackA)->next;
        tempB->nb = tempA->nb;
        tempB->next = *stackB;
        *stackB = tempB;

        free(tempA);
    }
    else
        printf("Stack A: empty\n");
}

int main(int argc, char **argv)
{
    int i;
    int nb;

    i = 1;

    t_stackA *stack_A = NULL;
    t_stackB *stack_B = ft_create_stack_b();
    while (i < argc)
    {
        nb = atoi(argv[i]);
        ft_add(&stack_A, nb);
        i++;
    }

    ft_print_stack(stack_A, stack_B, STACK_A);

    push_b(&stack_A, &stack_B);
    printf("\n");

    ft_print_stack(stack_A, stack_B, STACK_B);
    printf("\n");
    ft_print_stack(stack_A, stack_B, STACK_A);
    printf("\n");

    return 0;
}