/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:08:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:46:56 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_one(t_stack_node_struct **dest, t_stack_node_struct **src)
{
	*dest = *src;
	(*dest)->next = NULL;
	(*dest)->prev = NULL;
	*src = NULL;
}

void	set_two(t_stack_node_struct **dest, t_stack_node_struct **src)
{
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = NULL;
	(*dest)->prev = NULL;
	(*src)->prev = NULL;
}

void	set_three(t_stack_node_struct **dest, t_stack_node_struct **src)
{
	(*src)->next = *dest;
	*dest = *src;
	(*dest)->next->prev = *dest;
	*src = NULL;
}

void	set_four(t_stack_node_struct **dest, t_stack_node_struct **src)
{
	*src = (*src)->next;
	(*src)->prev->next = *dest;
	*dest = (*src)->prev;
	(*dest)->next->prev = *dest;
	(*src)->prev = NULL;
}

void	push(t_stack_node_struct **dest, t_stack_node_struct **src)
{
	if (src == NULL || *src == NULL || stack_len(*src) == 0)
		return ;
	if (*dest == NULL)
	{
		if ((*src)->next == NULL)
			set_one(dest, src);
		else
			set_two(dest, src);
	}
	else
	{
		if ((*src)->next == NULL)
			set_three(dest, src);
		else
			set_four(dest, src);
	}
}
