/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:29 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/14 13:51:31 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countword(const char *str, char c)
{
	size_t	count;
	size_t	i;

	if (c == 0)
		return (1);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i + 1] == c && str[i] != c)
			count++;
		if (str[i] != c && str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

static size_t	countletter(char *str, char c)
{
	size_t	count;

	count = 0;
	while (str[count] != c && str[count])
		count++;
	return (count);
}

static char	**free_letter(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**put_malloc(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < countword(s, c))
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			tab[j] = ft_substr(s, i, countletter((char *)s + i, c));
			if (!tab[j])
				return (free_letter(tab));
			i += countletter((char *)s + i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (s == NULL || (s[0] == 0 && c == 0))
	{
		tab = (char **)malloc(sizeof(char *) * 1);
		if (!tab)
			return (NULL);
		tab[0] = 0;
		return (tab);
	}
	tab = (char **)malloc(sizeof(char *) * (countword(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = put_malloc(s, c, tab);
	if (!tab)
		return (NULL);
	return (tab);
}
