#include "push_swap.h"


static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static long	ft_atol(const char *s) //Define a function that converts every string into a long value
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void ft_add_node(t_stack **stack, int n)
{
    t_stack *node;
    t_stack *last_node;

    if(!stack)
        return;
    node = malloc(sizeof(t_stack));
    if (!node)
        return;
    node->next = NULL;
    node->nb = n;
    if(!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = ft_stack_last(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

void ft_create_stack_a(t_stack **A, char **argv)
{
    long n;
    int i; 

    i = 0;
    while (argv[i])
    {
        if(ft_e_syntax(argv[i]))
            ft_free_errors(A);
        n = ft_atol(argv[i]);
        if(n > INT_MAX || n < INT_MIN)
            ft_free_errors(A);
        if(ft_e_duplicated(*A, (int)n))
            ft_free_errors(A);
        ft_add_node(A, (int)n);
        i++;
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

// void ft_print_stacks(const t_stack *A, const t_stack *B)
// {
//     printf("\nStack A:\n");
//     const t_stack *tempA = A;
//     while (tempA != NULL)
//     {
//         printf("%ld\n", tempA->nb);
//         tempA = tempA->next;
//     }

//     printf("\nStack B:\n");
//     const t_stack *tempB = B;
//     while (tempB != NULL)
//     {
//         printf("%ld\n", tempB->nb);
//         tempB = tempB->next;
//     }
// }
