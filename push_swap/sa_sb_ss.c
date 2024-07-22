/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:11:26 by largenzi          #+#    #+#             */
/*   Updated: 2024/05/04 16:46:56 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node_struct **head)
{
	if (*head == NULL || head == NULL || stack_len(*head) <= 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next != NULL)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node_struct	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node_struct **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node_struct **a, t_stack_node_struct **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
