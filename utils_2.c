/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 03:46:18 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/28 14:27:20 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

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
