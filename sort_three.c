/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:24:06 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/24 23:50:41 by edjebri          ###   ########.fr       */
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
