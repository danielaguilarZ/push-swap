#include "push_swap.h"


// Rotation Operation

void	ft_rotation(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	*stack = ft_stack_last(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	ft_ra(t_stack **A, bool print)
{
    ft_rotation(A);
    if(print == true)
        printf("ra\n");
}

void	ft_rb(t_stack **B, bool print)
{
    ft_rotation(B);
    if(print == true)
        printf("rb\n");
}

void	ft_rr(t_stack **A, t_stack **B, bool print)
{
    ft_rotation(A);
    ft_rotation(B);
    if(print == true)
        printf("rr\n");
}