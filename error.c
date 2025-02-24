/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:31:40 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/24 02:07:00 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	printf("NO Error\n");
	return (0);
}

void	free_split(char **argv)
{
	int	i;
	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
	{
		free(argv[i++]);
		printf("free%d\n", i);
	}
	free(argv - 1);
}

void	error_free(t_stack_node **a, char **argv, int splitted)
{
	free_stack(a);
	if (splitted)
		free_split(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_repeat(t_stack_node *a, long nbr)
{
	t_stack_node	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr == (int)nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
