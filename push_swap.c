/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:41:47 by silent            #+#    #+#             */
/*   Updated: 2025/03/04 01:27:55 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1]);
	init_stack_a(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}

static int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == ' '))
			str++;
		if (*str)
			count++;
		while (*str && (*str != ' '))
			str++;
	}
	return (count);
}

static int	word_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] && (str[len] != ' '))
		len++;
	return (len);
}

static char	*next_word(char **str)
{
	char	*word;
	int		len;
	int		i;

	while (**str && (**str == ' '))
		(*str)++;
	len = word_length(*str);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = **str;
		(*str)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		words;
	int		i;

	words = count_words(str);
	tab = malloc(sizeof(char *) * (words + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (i <= words)
	{
		if (i == 0)
		{
			tab[i] = malloc(sizeof(char));
			if (!tab[i])
				return (NULL);
			tab[i++][0] = '\0';
			continue ;
		}
		tab[i++] = next_word(&str);
	}
	tab[i] = NULL;
	return (tab);
}
