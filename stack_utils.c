/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:12:54 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/24 18:14:45 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/*
 * Search for the last node and append
 * 🚨 Pay attention if the stack empty?
*/
void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_sorted(t_stack_node *head)
{
	int	nb;

	nb = head-> nbr;
	while (head->next)
	{
		head = head->next;
		if (nb > head->nbr)
			return (0);
	}
	return (1);
}

int	stack_len(t_stack_node *head)
{
	int	i;

	i = 0;
	while (head->next)
	{
		head = head->next;
		i++;
	}
	return (i);
}
