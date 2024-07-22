/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:10:50 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:50:57 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node_struct **stack)
{
	t_stack_node_struct	*last;

	if (stack == NULL || *stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	last = find_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node_struct **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node_struct **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node_struct **a, t_stack_node_struct **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
