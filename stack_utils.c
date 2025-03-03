/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:12:54 by edjebri           #+#    #+#             */
/*   Updated: 2025/03/03 16:37:59 by edjebri          ###   ########.fr       */
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

	if (!head)
		return (0);
	i = 1;
	while (head->next)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_stack_node	*highest(t_stack_node *head)
{
	long	nb;
	t_stack_node	*highest;

	if (!head)
		return (NULL);
	nb = LONG_MIN;
	highest = NULL;
	while (head)
	{
		if (nb < head->nbr)
		{
			highest = head;
			nb = head->nbr;
		}
		head = head->next;
	}
	return (highest);
}
