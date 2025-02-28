/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:24:06 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/28 03:30:55 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	if ((*a)->nbr == highest(*a))
		ra(a);
	else if ((*a)->next->nbr == highest(*a))
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	update_metadata_a(t_stack_node *a, t_stack_node *b)
{
	update_index(a);
	update_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}
void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target;
	long			closest_nbr;

	while (a)
	{
		closest_nbr = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > closest_nbr)
			{
				closest_nbr = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		a->target_node = target;
		if (closest_nbr == LONG_MIN)
			a->target_node = highest(b);
		a = a->next;
	}
}

void	push_cost(t_stack_node *a, int stack_len)
{
	if (a->above_median)
		return (a->index);
	else
		return ((stack_len - a->index));
}

 int	ft_max(int a, int b)
 {
	if (a < b)
		return (b);
	else
		return (a);
 }

