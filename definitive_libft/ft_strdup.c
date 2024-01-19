/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:41:28 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/17 11:33:40 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)malloc (sizeof (char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, (ft_strlen(s) + 1));
	return (str);
}
