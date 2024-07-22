/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializtion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:07:42 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:46:56 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_everything(t_stack_node_struct *a, t_stack_node_struct *b)
{
	find_target(a, b);
	set_node_position(a);
	set_node_median(a);
	set_node_position(b);
	set_node_median(b);
	find_cost(a, b);
	find_cheapest(b);
}
