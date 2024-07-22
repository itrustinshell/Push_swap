/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_argv_into_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:37:31 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/23 16:24:31 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_argv_into_stack(t_stack_node_struct **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_it_number(argv[i]))
			error_free_list_and_argv(a, argv, argc);
		n = ft_atoi(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			error_free_list_and_argv(a, argv, argc);
		if (error_repetition(*a, (int)n))
			error_free_list_and_argv(a, argv, argc);
		append_node(a, (int)n);
		i++;
	}
	if (argc == 2)
	{
		printf("pisello\n");
		free_created_argv(argv);
	}
}
