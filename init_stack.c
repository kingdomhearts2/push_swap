/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:27:01 by edjebri           #+#    #+#             */
/*   Updated: 2025/03/04 01:21:40 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	init_stack_a(t_stack_node **a, char **argv, int splitted)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, splitted);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, splitted);
		if (error_repeat(*a, (int)nbr))
			error_free(a, argv, splitted);
		append_node(a, (int)nbr);
		++i;
	}
	if (splitted)
		free_split(argv);
}

void	smallest_first(t_stack_node **a)
{
	while ((*a)->nbr != smallest((*a))->nbr)
	{
		if (smallest((*a))->above_median)
			ra(a);
		else
			rra(a);
	}
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}
