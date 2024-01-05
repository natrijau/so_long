/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:56:49 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/02 17:04:37 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ccs1;
	unsigned char	*ccs2;

	i = 0;
	ccs1 = (unsigned char *) s1;
	ccs2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ccs1[i] != ccs2[i])
			return (ccs1[i] - ccs2[i]);
		i++;
	}
	return (0);
}
