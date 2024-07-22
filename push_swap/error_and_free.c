/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:33:58 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/23 16:55:09 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_created_argv(char **argv)
{
	int	i;

	i = 1;
	if (argv == NULL || argv[i] == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_evry_single_node(t_stack_node_struct **stack)
{
	t_stack_node_struct	*copy;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack != NULL)
	{
		copy = (*stack)->next;
		free(*stack);
		*stack = copy;
	}
}

void	error_free_list_and_argv(t_stack_node_struct **a, char **argv, int argc)
{
	free_evry_single_node(a);
	if (argc == 2)
		free_created_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_repetition(t_stack_node_struct *a, int n)
{
	int	is_doubled;
	int	is_unique;

	is_doubled = 1;
	is_unique = 0;
	if (a == NULL)
		return (is_unique);
	while (a != NULL)
	{
		if (a->value == n)
			return (is_doubled);
		a = a->next;
	}
	return (is_unique);
}
