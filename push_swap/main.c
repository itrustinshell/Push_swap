/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:33:15 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/16 17:30:14 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node_struct	*a;
	t_stack_node_struct	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else if (argc == 2)
		argv = ft_split_modified_for_argv(argv[1]);
	if (argv == NULL)
		return (0);
	put_argv_into_stack(&a, argv, argc);
	if (is_stack_sorted(a) == 0)
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three_nodes(&a);
		else
			push_swap(&a, &b);
	}
	free_evry_single_node(&a);
}
