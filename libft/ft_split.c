/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 07:59:38 by migferna          #+#    #+#             */
/*   Updated: 2019/11/20 15:22:57 by migferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_cont(char const *s, char c)
{
	int it;
	int cont;

	it = 0;
	cont = 0;
	while (s[it])
	{
		if (s[it] == c)
			it++;
		else
		{
			cont++;
			while (s[it] != '\0' && s[it] != c)
				it++;
		}
	}
	return (cont);
}

static int	ft_strnlen(char const *s, char c)
{
	int cont;

	cont = 0;
	while (*s != '\0' && *s != c)
	{
		cont++;
		s++;
	}
	return (cont);
}

char		**ft_split(char const *s, char c)
{
	char	**table;
	int		word;
	int		j;
	int		it;

	if (!s)
		return (NULL);
	it = 0;
	j = 0;
	word = 0;
	if (!(table = malloc(sizeof(char *) * (ft_words_cont(s, c) + 1))))
		return (NULL);
	while (word < ft_words_cont(s, c))
	{
		while (s[it] == c)
			it++;
		if (!(table[word] = malloc(sizeof(char) * ft_strnlen(&s[it], c) + 1)))
			return (NULL);
		j = 0;
		while (s[it] != c && s[it])
			table[word][j++] = s[it++];
		table[word++][j] = '\0';
	}
	table[word] = NULL;
	return (table);
}
