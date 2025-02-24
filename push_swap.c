/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:41:47 by silent            #+#    #+#             */
/*   Updated: 2025/02/24 14:48:13 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
//	t_stack_node	*b;

	a = NULL;
//	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
		printf("pas trié");
		/*
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}*/
	else
		printf("trié");
	free_stack(&a);
	return (0);
}

static int	is_charset(char c, char charset)
{
	return (c == charset);
}

static int	count_words(char *str, char charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str)
			count++;
		while (*str && !is_charset(*str, charset))
			str++;
	}
	return (count);
}

static int	word_length(char *str, char charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_charset(str[len], charset))
		len++;
	return (len);
}

static char	*next_word(char **str, char charset)
{
	char	*word;
	int		len;
	int		i;

	while (**str && is_charset(**str, charset))
		(*str)++;
	len = word_length(*str, charset);
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

char	**ft_split(char *str, char charset)
{
	char	**tab;
	int		words;
	int		i;

	words = count_words(str, charset);
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
			continue;
		}
		tab[i++] = next_word(&str, charset);
	}
	tab[i] = NULL;
	return (tab);
}
