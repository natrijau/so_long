/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:50 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/19 15:18:25 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../definitive_libft/get_next_line.h"
#include "../definitive_libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#include "./main.h"
#include "./parsing_map.h"

// void	free_map2(t_map_texture *content)
// {
// 	int	i;

// 	i = 0;
// 	while (content->map[i])
// 	{
// 		free(content->map[i]);
// 		i++;
// 	}
// 	free(content->map);
// }

int	check_last_line(t_map_texture *content)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (content->map[i])
		i++;
	// count_line = i - 2;
	while (content->map[i - 1][j])
	{
		if (content->map[i - 1][j] != '1')
		{
			printf("erreur mur derniere ligne\n");
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
			printf("erreur mur premiere ligne\n");
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
			printf("erreur mur premiere ou derniere colonne\n");
			return (1);
		}
		i++;
	}
	test_in_map (count_line, count_column, content);
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
			printf ("le nombre de colonnes ne correspond pas!");
			return (1);
		}
		i++;
	}
	result = check_walls(content);
	return (result);
}
