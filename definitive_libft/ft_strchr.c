/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:52:15 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/09 08:50:25 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*s_cpy;
	unsigned char	c_cpy;

	i = 0;
	s_cpy = (unsigned char *) s;
	c_cpy = (unsigned char) c;
	while (s_cpy[i])
	{
		if (s_cpy[i] == c_cpy)
			return ((char *)&s[i]);
		i++;
	}
	if (c_cpy == '\0')
		return ((char *)&s_cpy[i]);
	return (0);
}
