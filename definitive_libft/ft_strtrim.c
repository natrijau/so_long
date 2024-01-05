/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:02:25 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/06 16:21:13 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_end(const char *str, const char *set)
{
	unsigned int	i;
	size_t			y;

	y = ft_strlen(str) - 1;
	i = 0;
	while (set[i])
	{
		if (set[i] != str[y])
			i++;
		if (set[i] == str[y])
		{
			y--;
			i = 0;
		}
	}
	return (y);
}

int	check_start(const char *str, const char *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] != str[j])
			i++;
		if (set[i] == str[j])
		{
			j++;
			i = 0;
		}
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	char_start;
	unsigned int	char_end;
	unsigned int	len_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	char_start = check_start(s1, set);
	char_end = check_end(s1, set);
	len_str = (char_end - char_start) + 1;
	if (char_start == ft_strlen(s1) || char_end == ft_strlen(s1))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_substr(s1, char_start, len_str);
	if (!str)
		return (NULL);
	return (str);
}
