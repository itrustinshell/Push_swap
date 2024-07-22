/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_properties_of_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:11:44 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:46:56 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_node_position(t_stack_node_struct *stack)
{
	int	i;

	if (stack == NULL)
		return ;
	i = 0;
	while ((stack) != NULL)
	{
		(stack)->position = i;
		i++;
		(stack) = (stack)->next;
	}
}

void	set_node_median(t_stack_node_struct *stack)
{
	int	length;

	if (stack == NULL)
		return ;
	length = stack_len(stack);
	while ((stack) != NULL)
	{
		if ((stack)->position <= length / 2)
			(stack)->on_the_median = 1;
		else
			(stack)->on_the_median = -1;
		(stack) = (stack)->next;
	}
}

void	find_target(t_stack_node_struct *a,
							t_stack_node_struct *b)
{
	int					value;
	t_stack_node_struct	*target;
	t_stack_node_struct	*tmp;

	tmp = a;
	while (b != NULL)
	{
		value = 2147483647;
		a = tmp;
		while (a != NULL)
		{
			if (b->value < a->value && a->value < value)
			{
				value = a->value;
				target = a;
			}
			a = a->next;
		}
		if (value == 2147483647)
			b->target = find_smallest(tmp);
		else
			b->target = target;
		b = b->next;
	}
}

void	find_cost(t_stack_node_struct *a, t_stack_node_struct *b)
{
	int	price;
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b != NULL)
	{
		price = b->position;
		if (b->on_the_median == 1)
			price = b->position;
		else
			price = len_b - b->position;
		if (b->target->on_the_median == 1)
			price = price + b->target->position;
		else
			price = price + len_a - b->target->position;
		b->cost = price;
		b = b->next;
	}
}

void	find_cheapest(t_stack_node_struct *b)
{
	int					value;
	t_stack_node_struct	*node_to_change;

	if (b == NULL)
		return ;
	value = b->cost;
	node_to_change = b;
	b = b->next;
	while (b != NULL)
	{
		if (b->cost < value)
		{
			value = b->cost;
			node_to_change = b;
		}
		b = b->next;
	}
	node_to_change->cheapest = 1;
}
