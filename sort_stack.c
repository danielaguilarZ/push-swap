#include "push_swap.h"

static void ft_move_a_to_b(t_stack **A, t_stack **B)
{
    t_stack *optimal_node;

    optimal_node = ft_get_optimal(*A);
    if (optimal_node->above_median && optimal_node->target_node->above_median)
        ft_rr_both(A, B, optimal_node);
    else if (!(optimal_node->above_median) && !(optimal_node->target_node->above_median))
        ft_rrr_both(A, B, optimal_node);
    ft_ready_to_push(A, optimal_node, 'A');
    ft_ready_to_push(B, optimal_node->target_node, 'B');
    ft_pb(A, B, true);
}

static void ft_move_b_to_a(t_stack **B, t_stack **A)
{
    ft_ready_to_push(A, (*B)->target_node, 'A');
    ft_pa(B, A, true);
}

static void ft_min_first(t_stack **A)
{
    while((*A)->nb != ft_stack_min(*A)->nb)
    {
        if(ft_stack_min(*A)->above_median)
            ft_ra(A, true);
        else
            ft_rra(A, true);
    }
}

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
        ft_move_a_to_b(A, B);
    }
    ft_sort_three(A);
    while (*B)
    {
        ft_nodes_B(*A, *B);
        ft_move_b_to_a(B, A);
    }
    ft_current_index(*A);
    ft_min_first(A);

}