/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:19:51 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/28 14:55:07 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack_node **stack,
	t_stack_node *top_node,
	char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	update_metadata_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			closest_nbr;

	while (b)
	{
		closest_nbr = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < closest_nbr)
			{
				closest_nbr = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		b->target_node = target;
		if (closest_nbr == LONG_MAX)
			a->target_node = smallest(a);
		b = b->next;
	}
}

t_stack_node	*smallest(t_stack_node *head)
{
	long	nb;
	t_stack_node	*smallest;

	nb = LONG_MAX;
	while (head->next)
	{
		if (nb > head->nbr)
		{
			smallest = head;
			nb = head->nbr;
		}
		head = head->next;
	}
	return (smallest);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}
