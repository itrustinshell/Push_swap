/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_stack_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:08:43 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/22 16:55:13 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack_node_struct *stack)
{
	int	sorted;

	sorted = 1;
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
		{
			sorted = 0;
			return (sorted);
		}
		stack = stack->next;
	}
	return (sorted);
}

t_stack_node_struct	*find_highest(t_stack_node_struct *stack)
{
	t_stack_node_struct	*h;

	if (stack == NULL)
		return (NULL);
	h = stack;
	while (stack -> next != NULL)
	{
		if (h -> value < stack -> next -> value)
			h = stack -> next;
		stack = stack -> next;
	}
	return (h);
}

t_stack_node_struct	*find_last_node(t_stack_node_struct *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	append_node(t_stack_node_struct **stack, int nbr)
{
	t_stack_node_struct	*node;
	t_stack_node_struct	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node_struct));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node_struct	*find_smallest(t_stack_node_struct *stack)
{
	long				smallest;
	t_stack_node_struct	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}
