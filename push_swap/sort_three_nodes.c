/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:43:53 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:57:20 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_stack_node_struct **a)
{
	if (*a == find_smallest(*a))
	{
		ra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
		rra(a);
		return ;
	}
	else if ((*a)->next == find_smallest(*a))
	{
		if (*a == find_highest(*a))
			ra(a);
		else
			sa(a);
	}
	else
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		rra(a);
	}
}
