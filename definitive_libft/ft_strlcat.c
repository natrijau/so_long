/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:31:41 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/03 11:05:36 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	j;
	size_t	len_src;

	j = 0;
	if ((dst == NULL || src == NULL) && size == 0)
		return (0);
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (len_src + size);
	while (src[j] && j + len_dest < (size - 1))
	{
		dst[len_dest + j] = src[j];
		j++;
	}
	dst[len_dest + j] = '\0';
	return (len_src + len_dest);
}
