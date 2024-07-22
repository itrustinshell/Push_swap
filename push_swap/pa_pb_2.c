/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:08:55 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:46:56 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node_struct **a, t_stack_node_struct **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node_struct **b, t_stack_node_struct **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
