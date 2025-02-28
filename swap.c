/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:53:22 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/28 14:29:56 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *stack;
	first_node->prev = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	second_node->prev = NULL;
	*stack = second_node;
}

void	rotate(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	last_node = find_last_node(*stack);
	first_node = *stack;
	*stack = first_node->next;
	last_node->next = first_node;
	first_node->next->prev = NULL;
	first_node->next = NULL;
	first_node->prev = last_node;
}

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	last_node = find_last_node(*stack);
	first_node = *stack;
	*stack = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a,t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a,t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
