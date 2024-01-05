/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:57:18 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:20 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*copydest;
	unsigned char	*copysrc;

	copydest = (unsigned char *) dest;
	copysrc = (unsigned char *) src;
	if (dest > src)
	{
		while (n > 0)
		{
			copydest[n - 1] = copysrc[n - 1];
			n--;
		}
		return ((void *)copydest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
