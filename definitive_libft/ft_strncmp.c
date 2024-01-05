/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:12:35 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/02 13:04:39 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ccs1;
	unsigned char	*ccs2;

	i = 0;
	ccs1 = (unsigned char *) s1;
	ccs2 = (unsigned char *) s2;
	while ((ccs1[i] || ccs2[i]) && i < n)
	{
		if (ccs1[i] > ccs2[i] || ccs1[i] < ccs2[i])
			return (ccs1[i] - ccs2[i]);
		i++;
	}
	return (0);
}
