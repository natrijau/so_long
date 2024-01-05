/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:54:35 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/13 15:05:37 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_n(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*put_tab(char *tab, int count, int n, int nb)
{
	while (count >= 0)
	{
		tab[count] = n % 10 + 48;
		n = n / 10;
		count--;
	}
	if (nb == 1)
		tab[0] = '-';
	return (tab);
}

char	*ft_itoa(int n)
{
	int		nb;
	int		count;
	char	*tab;

	nb = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		nb = 1;
		n *= -1;
	}
	count = size_n(n) + nb;
	tab = (char *)malloc(sizeof(char) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = 0;
	count--;
	return (put_tab(tab, count, n, nb));
}
