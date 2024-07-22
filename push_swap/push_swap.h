/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: largenzi <largenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:06:56 by largenzi          #+#    #+#             */
/*   Updated: 2024/06/23 09:39:06 by largenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					position;
	int					final_index;
	int					cost;
	int					on_the_median;
	int					cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node_struct;	

char				*generate_element_in_matrix(char *src);
void				free_elements_of_matrix(char **matrix, int i);
int					is_stack_sorted(t_stack_node_struct *stack);
t_stack_node_struct	*find_highest(t_stack_node_struct *stack);
t_stack_node_struct	*find_smallest(t_stack_node_struct *stack);
t_stack_node_struct	*find_last_node(t_stack_node_struct *head);
int					stack_len(t_stack_node_struct *stack);
void				append_node(t_stack_node_struct **stack, int nbr);
t_stack_node_struct	*recall_cheapest(t_stack_node_struct *stack);
void				finish_rotation(t_stack_node_struct **s,
						t_stack_node_struct *n, char c);
int					error_repetition(t_stack_node_struct *a, int nbr);
void				error_free_list_and_argv(t_stack_node_struct **a,
						char **argv, int argc);
void				free_created_argv(char **argv);
void				free_evry_single_node(t_stack_node_struct **stack);
void				initialize_everything(t_stack_node_struct *a,
						t_stack_node_struct *b);
void				set_node_position(t_stack_node_struct *stack);
void				set_node_median(t_stack_node_struct *stack);
void				find_target(t_stack_node_struct *a, t_stack_node_struct *b);
void				find_cost(t_stack_node_struct *a, t_stack_node_struct *b);
void				find_cheapest(t_stack_node_struct *b);
void				sort_three_nodes(t_stack_node_struct **a);
void				push_swap(t_stack_node_struct **a, t_stack_node_struct **b);
char				**ft_split_modified_for_argv(char *str);
long				ft_atoi(const char *str);
int					is_it_number(char *input_num);
void				put_argv_into_stack(t_stack_node_struct **a,
						char **argv, int argc);
void				push(t_stack_node_struct **dest, t_stack_node_struct **src);
void				reverse_rotate(t_stack_node_struct **stack);
void				rotate_both(t_stack_node_struct **a,
						t_stack_node_struct **b,
						t_stack_node_struct *cheapest_node);
void				reverse_rotate_both(t_stack_node_struct **a,
						t_stack_node_struct **b,
						t_stack_node_struct *cheapest_node);
void				pa(t_stack_node_struct **a, t_stack_node_struct **b);
void				pb(t_stack_node_struct **b, t_stack_node_struct **a);
void				sa(t_stack_node_struct **a);
void				sb(t_stack_node_struct **b);
void				ss(t_stack_node_struct **a, t_stack_node_struct **b);
void				ra(t_stack_node_struct **a);
void				rb(t_stack_node_struct **b);
void				rr(t_stack_node_struct **a, t_stack_node_struct **b);
void				rra(t_stack_node_struct **a);
void				rrb(t_stack_node_struct **b);
void				rrr(t_stack_node_struct **a, t_stack_node_struct **b);
void				move_nodes(t_stack_node_struct **a,
						t_stack_node_struct **b);

#endif