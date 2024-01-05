/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:17:54 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/02 16:57:15 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cps;

	cps = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (cps[i] == (unsigned char)c)
			return (&cps[i]);
		i++;
	}
	return (0);
}
