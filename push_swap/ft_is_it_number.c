/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_it_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:34:30 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/23 09:37:56 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_number(char *input_num)
{
	int	wrong;
	int	correct;
	int	i;

	wrong = 1;
	correct = 0;
	if (input_num == NULL || input_num[0] == '\0')
		return (wrong);
	i = 0;
	if (input_num[i] == '+' || input_num[i] == '-')
		i++;
	if (input_num[i] == '\0')
		return (wrong);
	while (input_num[i] >= '0' && input_num[i] <= '9')
		i++;
	if (input_num[i] == '\0')
		return (correct);
	else
		return (wrong);
}
