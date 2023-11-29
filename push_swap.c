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

Node *top;

top = NULL;

int	checker_duplicated(int value)
{
	Node	*current;

	current = top;
	while (current != NULL)
	{
		if (current->data == value)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void create_stack_a(int nb)
{
    Node *newNode;
    
    if (checker_duplicated(nb) == 1)
    {
        printf("Error: Number already on the stack\n");
        exit(EXIT_FAILURE);
    }
    newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Error: Memory could not be allocated");
        exit(EXIT_FAILURE);
    }

    newNode->data = nb;
    newNode->next = top;
    top = newNode;
}