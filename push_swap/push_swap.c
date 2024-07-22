/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:09:19 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:55:27 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node_struct **a,
						t_stack_node_struct **b,
						t_stack_node_struct *cheapest_node) {
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rr(a, b);
	set_node_position(*a);
	set_node_median(*a);
	set_node_position(*b);
	set_node_median(*b);
}

void	reverse_rotate_both(t_stack_node_struct **a,
								t_stack_node_struct **b,
								t_stack_node_struct *cheapest_node) {
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rrr(a, b);
	set_node_position(*a);
	set_node_median(*a);
	set_node_position(*b);
	set_node_median(*b);
}

void	finish_rotation(t_stack_node_struct **stack,
							t_stack_node_struct *first_node,
							char stack_name) {
	while (*stack != first_node)
	{
		if (stack_name == 'a')
		{
			if (first_node->on_the_median == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (first_node->on_the_median == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_nodes(t_stack_node_struct **a, t_stack_node_struct **b)
{
	t_stack_node_struct	*cheapest_node;

	cheapest_node = recall_cheapest(*b);
	if (cheapest_node->on_the_median == 1
		&& cheapest_node->target->on_the_median == 1)
		rotate_both(a, b, cheapest_node);
	else if ((cheapest_node->on_the_median == -1)
		&& (cheapest_node->target->on_the_median == -1))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	pa(a, b);
}

void	push_swap(t_stack_node_struct **a, t_stack_node_struct **b)
{
	t_stack_node_struct	*smallest;
	int					len_a;

	len_a = stack_len(*a);
	while (len_a > 3)
	{
		pb(b, a);
		len_a--;
	}
	sort_three_nodes(a);
	while (*b != NULL)
	{
		initialize_everything(*a, *b);
		move_nodes(a, b);
	}
	set_node_position(*a);
	set_node_median(*a);
	smallest = find_smallest(*a);
	if (smallest->on_the_median == 1)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
