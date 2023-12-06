#include "push_swap.h"

void ft_sort_all(t_stack **A, t_stack **B)
{
    int size_stack_a;

    size_stack_a = ft_stack_size(*A);
    if (size_stack_a-- > 3 && ft_stack_sorted(*A) == false)
        ft_pb(A, B, true);
    if (size_stack_a-- > 3 && ft_stack_sorted(*A) == false)
        ft_pb(A, B, true);
    while(size_stack_a-- > 3 && ft_stack_sorted(*A) == false)
    {
        ft_nodes_A(*A, *B);
        ft_move_a_to_b(a, b);
    }
    ft_sort_three(A);
    while (*B)
    {
        ft_nodes_B(*A, *B);
        ft_move_b_to_a(b, a);
    }

}