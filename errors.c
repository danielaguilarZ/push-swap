#include "push_swap.h"

int ft_e_syntax(char *str)
{
    if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str) 
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int ft_e_duplicated(t_stack *A, int n)
{
	if (!A)
		return (0);
	while (A)
	{
		if ((A->nb) == n)
			return (1);
		A = A->next;
	}
	return (0);
}

void ft_free_stack(t_stack **stack)
{
	t_stack *tmp;
	t_stack *current;

	if(!stack)
		return;
	while (current)
	{
		tmp = current->next;
		current->nb = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void ft_free_errors(t_stack **A)
{
	ft_free_stack(A);
	printf("Error\n");
	exit (1);
}