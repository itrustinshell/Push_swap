/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:11:15 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:51:48 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node_struct **stack)
{
	t_stack_node_struct	*last_node;

	if (stack == NULL || *stack == NULL || stack_len(*stack) <= 1)
		return ;
	last_node = find_last_node(*stack);
	last_node -> next = (*stack);
	(*stack) = last_node;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->next->prev = *stack;
}

void	rra(t_stack_node_struct **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node_struct **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node_struct **a, t_stack_node_struct **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
