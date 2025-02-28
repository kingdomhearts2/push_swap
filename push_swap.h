/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:42:39 by silent            #+#    #+#             */
/*   Updated: 2025/02/28 14:28:55 by edjebri          ###   ########.fr       */
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

void	ss(t_stack_node **a,t_stack_node **b);
void	sb(t_stack_node **b);
void	sa(t_stack_node **a);

void	rr(t_stack_node **a,t_stack_node **b);
void	rb(t_stack_node **b);
void	ra(t_stack_node **a);

void	rrr(t_stack_node **a, t_stack_node **b);
void	rrb(t_stack_node **b);
void	rra(t_stack_node **a);

t_stack_node		*highest(t_stack_node *head);
void	sort_three(t_stack_node **a);

void	reverse_rotate(t_stack_node **stack);
void	longest_sorted(t_stack_node *node);

void	move_b_to_a(t_stack_node **a, t_stack_node **b);
void	smallest_first(t_stack_node **a);
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	update_metadata_a(t_stack_node *a, t_stack_node *b);
void	update_metadata_b(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_cheapest(t_stack_node *a);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	current_index(t_stack_node *a);
void	push_swap(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);
void	pa(t_stack_node **a, t_stack_node **b);
void	rotate(t_stack_node **stack);
int		push_cost(t_stack_node *a, int len_a);
int	ft_max(int a, int b);
t_stack_node	*smallest(t_stack_node *head);
void	rev_rotate_both(t_stack_node **a,
	t_stack_node **b,
	t_stack_node *cheapest_node);
void	prep_for_push(t_stack_node **stack,
	t_stack_node *top_node,
	char stack_name);

void	rotate_both(t_stack_node **a,
		t_stack_node **b,
		t_stack_node *cheapest_node);

void	set_target_b(t_stack_node *a, t_stack_node *b);
void	set_target_a(t_stack_node *a, t_stack_node *b);
void	cost_analysis_a(t_stack_node *a, t_stack_node *b);
#endif
