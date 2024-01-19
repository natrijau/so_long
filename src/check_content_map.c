/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:50:40 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/18 10:33:24 by natrijau         ###   ########.fr       */
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

int	player_exit_collectible(t_map_texture *content)
{
	int	player;
	int	exit;
	int	collectible;

	player = content->the_player;
	exit = content->exit;
	collectible = content->collectible;
	if (player != 1 || exit != 1 || collectible < 1)
	{
		printf("Erreur sur le player, la sortie ou le collectible !\n");
		error();
		return (1);
	}
	return (0);
}

t_map_texture	*check_boxes_and_add(t_map_texture *content, int i, int j)
{
	if (content->map[i][j] == 'C')
		content->collectible++;
	if (content->map[i][j] == 'E')
		content->exit++;
	if (content->map[i][j] == 'P')
	{
		content->the_player++;
		content->x = i;
		content->y = j;
	}
	return (content);
}

int	check_boxes_valid(t_map_texture *content, int i, int j)
{
	if ((((((content->map[i][j] != '1' && content->map[i][j] != 'E')
				&& content->map[i][j] != '0')) && content->map[i][j] != 'P')
					&& content->map[i][j] != 'C'))
	{
		printf("Une des cases de la map n'est pas valide !\n");
		//stoper lexecution du programme
		error();
		return (1);
	}
	return (0);
}

int	presence_of_characters(t_map_texture *content, int col, int line)
{
	int				i;
	int				j;

	content->collectible = 0;
	content->exit = 0;
	content->the_player = 0;
	content->x = 0;
	content->y = 0;
	i = 1;
	j = 1;
	while (i <= line)
	{
		check_boxes_valid(content, i, j);
		content = check_boxes_and_add(content, i, j);
		j++;
		if (j == col)
		{
			i++;
			j = 1;
		}
	}
	player_exit_collectible(content);
	return (0);
}

//Test le contenue de la map
int	test_in_map(int line, int column, t_map_texture *content)
{
	// t_map_texture	*copie;

	// copie = malloc(sizeof(t_map_texture));
	presence_of_characters(content, column, line);
	content->map_copy = copy_content(content, line);
	// for (int i = 0; content->map_copy[i]; i++)
	// {
	// 	printf("copie[i] %s",content->map_copy[i]);
	// }
	
	content->map_copy = check_if_resolvable(content->map_copy, content->x, content->y);
	check_map(content->map_copy, line, column);
	// free(content->map_copy);
	content->map_copy = NULL;
	return (0);
}
