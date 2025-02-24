/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:42:39 by silent            #+#    #+#             */
/*   Updated: 2025/02/24 20:01:13 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

char	**ft_split(char *str, char charset);
long	ft_atol(char *str);
int		error_syntax(char *str);
void	init_stack_a(t_stack_node **a, char **argv, int splitted);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **a, char **argv, int splitted);
int	error_repeat(t_stack_node *a, long nbr);
void	append_node(t_stack_node **stack, int nbr);
void	free_split(char **argv);
int	stack_sorted(t_stack_node *head);
int	stack_len(t_stack_node *head);
t_stack_node	*find_last_node(t_stack_node *head);

#endif
