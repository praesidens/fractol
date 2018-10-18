/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:09:46 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/07 06:01:55 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char *str, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (1)
	{
		while (*str == c)
			str++;
		if (*str)
			i++;
		else
			return (i);
		while (*str != c && *str != 0)
			str++;
	}
	return (i);
}

static char	*ft_wordcpy(char *dst, char *src, char c)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (src[++i] != 0 && src[i] != c)
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

static int	find_len(char *str, char c)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (str[++i] != c && str[i] != 0)
		;
	return (i);
}

static char	**ft_maketab(char **tab, char *str, int words_count, char c)
{
	int		i;
	int		counter;
	int		word_len;

	i = 0;
	counter = 0;
	word_len = 0;
	while (i < words_count)
	{
		while (str[counter] == c)
			counter++;
		word_len = find_len(&str[counter], c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
		{
			while (--i >= 0)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		tab[i] = ft_wordcpy(tab[i], &str[counter], c);
		counter += word_len;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		words_count;
	int		j;

	j = 0;
	if (s)
	{
		str = (char *)s;
		words_count = ft_words_count((char *)s, c);
		if (!(tab = (char **)malloc(sizeof(char *) * (words_count + 1))))
			return (NULL);
		return (ft_maketab(tab, str, words_count, c));
	}
	return (NULL);
}
