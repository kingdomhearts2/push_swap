/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:30:00 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/28 14:30:17 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first_node;
	t_stack_node	*new_first_node_a;
	t_stack_node	*first_node_b;

	first_node = *a;
	new_first_node_a = first_node->next;
	new_first_node_a->prev = NULL;
	*a = new_first_node_a;
	if (*b == NULL)
		append_node(b, first_node->nbr);
	else
	{
		first_node_b = *b;
		first_node_b->prev = first_node;
		first_node->prev = NULL;
		first_node->next = first_node_b;
		*b = first_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(a, b);
	write(1, "pb\n", 3);
}
