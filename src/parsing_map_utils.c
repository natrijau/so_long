/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:48:11 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/17 12:07:07 by natrijau         ###   ########.fr       */
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

static	void	free_copy(char **copy, int line)
{
	int	i;

	i = 0;
	while (i <= line + 1)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

//Check si flood fil valid
int	check_map(char **copy, int line, int col)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < line)
	{
		if (!(copy[i][j] == '1' || copy[i][j] == 'V'
			|| copy[i][j] == '0'))
		{
			printf("map impossible a faire !\n");
			error();
			return (1);
		}
		if (j == col)
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	free_copy(copy, line);
	return (0);
}

//Flood_fil
char	**check_if_resolvable(char **copy, int x, int y)
{
	if (copy[x][y] != '1' && copy[x][y] != 'V')
	{
		copy[x][y] = 'V';
		check_if_resolvable(copy, x + 1, y);
		check_if_resolvable(copy, x - 1, y);
		check_if_resolvable(copy, x, y + 1);
		check_if_resolvable(copy, x, y - 1);
	}
	return (copy);
}

//Copy map
char	**copy_content(t_map_texture *content, int line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	line += 1;
	content->map_copy = malloc(sizeof(char *) * (line + 1));
	if (!content->map_copy)
		return (NULL);
	while (i <= line)
	{
		j = 0;
		content->map_copy[i] = malloc(sizeof(char)
				* ft_strlen(content->map[i]) + 1);
		while (content->map[i][j])
		{
			content->map_copy[i][j] = content->map[i][j];
			j++;
		}
		content->map_copy[i][j] = '\0';
		i++;
	}
	return (content->map_copy);
}
