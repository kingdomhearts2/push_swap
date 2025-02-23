#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./inc/libft/libft.h"


typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	int	above_median;
	int	cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node *prev;
} t_stack_node;


#endif
