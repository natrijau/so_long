/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:50 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/24 14:03:15 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

int	check_last_line(t_map_texture *content)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (content->map[i])
		i++;
	while (content->map[i - 1][j])
	{
		if (content->map[i - 1][j] != '1')
		{
			ft_putstr_fd("erreur mur derniere ligne\n", 2);
			return (1);
		}
		j++;
	}
	return (0);
}

// Check first line
int	check_first_line(t_map_texture *content)
{
	int	j;

	j = 0;
	while (content->map[0][j])
	{
		if (content->map[0][j] != '1')
		{
			ft_putstr_fd("erreur mur premiere ligne\n", 2);
			return (1);
		}
		j++;
	}
	return (0);
}

//cheque si contour de map ok
int	check_walls(t_map_texture *content)
{
	int	i;
	int	count_column;
	int	count_line;

	count_line = 0;
	i = 0;
	count_column = ft_strlen(content->map[i]) - 1;
	while (content->map[i])
		i++;
	count_line = i - 2;
	if (check_first_line(content) != 0 || check_last_line(content) != 0)
		return (1);
	i = 1;
	while (i <= count_line)
	{
		if (content->map[i][0] != '1' || content->map[i][count_column] != '1')
		{
			ft_putstr_fd("erreur mur premiere ou derniere colonne\n", 2);
			return (1);
		}
		i++;
	}
	if (test_in_map (count_line, count_column, content) != 0)
		return (1);
	return (0);
}

//Numb of column
int	check_size(t_map_texture *content)
{
	int	i;
	int	j;
	int	c;
	int	result;

	i = 0;
	j = 0;
	while (content->map[i])
	{
		c = 0;
		while (content->map[0][j])
			j++;
		while (content->map[i][c])
			c++;
		if (c != j)
		{
			ft_putstr_fd ("le nombre de colonnes ne correspond pas!", 2);
			return (1);
		}
		i++;
	}
	result = check_walls(content);
	return (result);
}
