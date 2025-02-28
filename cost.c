/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:03:26 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/28 03:45:37 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median == a->target_node->above_median)
			a->push_cost =
				ft_max(push_cost(a, len_a), push_cost(a->target_node, len_b));
		else
			a->push_cost = push_cost(a, len_a) +
				push_cost(a->target_node, len_b);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *a)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!a)
		return ;
	cheapest_value = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheapest_value)
		{
			cheapest_value = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = 1;
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		update_metadata_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		update_metadata_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	smallest_first(a);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

t_stack_node	*find_cheapest(t_stack_node *a)
{
	t_stack_node *cheapest_node;

	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
}

static void	rotate_both(t_stack_node **a,
	t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	update_index(*a);
	update_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
	t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
	update_index(*a);
	update_index(*b);
}
