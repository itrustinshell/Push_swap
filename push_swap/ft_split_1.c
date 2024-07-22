/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:37:05 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/23 09:37:12 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ' && *s)
			s++;
		if (*s != ' ' && *s)
		{
			count++;
			while (*s != ' ' && *s)
				s++;
		}
	}
	return (count);
}

char	**create_matrix_like_real_argv(int n)
{
	char	**output;

	output = (char **)malloc((n + 1 + 1) * sizeof(char *));
	if (output == NULL)
		return (NULL);
	return (output);
}

void	fill_matrix(char *src, char **matrix, int n_words)
{
	int	i;

	matrix[0] = NULL;
	i = 1;
	while (i < n_words + 1)
	{
		matrix[i] = generate_element_in_matrix(src);
		if (matrix[i] == NULL)
		{
			free_elements_of_matrix(matrix, i);
			matrix = NULL;
			return ;
		}
		i++;
	}
	matrix[i] = NULL;
}

char	**ft_split_modified_for_argv(char *str)
{
	char	**output;
	int		n_words;

	n_words = count_words(str);
	if (n_words == 0)
		return (NULL);
	output = create_matrix_like_real_argv(n_words);
	if (output == NULL)
		return (NULL);
	fill_matrix(str, output, n_words);
	return (output);
}
