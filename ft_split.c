/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:43:45 by edjebri           #+#    #+#             */
/*   Updated: 2025/02/24 02:16:53 by edjebri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
/*#include <stdio.h>

int	main(void)
{
	char	str[] = "Salut ca va ou quoi";
	char	charset[] = " ";
	char	**split = ft_split(str, charset);
	int i = 0;
	while (i < 5)
		printf("%s,", split[i++]);
}*/
