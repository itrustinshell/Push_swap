/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:19:47 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/23 09:38:24 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cpy(char *dst, char *src, int start, int len)
{
	int	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = '\0';
}

char	*generate_element_in_matrix(char *src)
{
	int			start;
	char		*output;
	static int	i;
	int			count;

	count = 0;
	if (src[i] != '\0')
	{
		while (src[i] == ' ' && src[i])
			i++;
		while (src[i] != ' ' && src[i])
		{
			count++;
			i++;
		}
	}
	output = (char *)malloc((count + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output[count] = '\0';
	start = i - count;
	ft_cpy(output, src, start, count);
	return (output);
}

void	free_elements_of_matrix(char **matrix, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
	matrix = NULL;
}
