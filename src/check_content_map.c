/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:50:40 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/24 14:02:48 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

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
		ft_putstr_fd("Erreur sur le player, la sortie ou le collectible !\n",
			2);
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
		ft_putstr_fd("Une des cases de la map n'est pas valide !\n", 2);
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
	if (player_exit_collectible(content) != 0)
		return (1);
	return (0);
}

//Test le contenue de la map
int	test_in_map(int line, int column, t_map_texture *content)
{
	if (presence_of_characters(content, column, line) != 0)
		return (1);
	content->map_copy = copy_content(content, line);
	content->map_copy = check_if_resolvable(content->map_copy,
			content->x, content->y);
	if (check_map(content->map_copy, line, column) != 0)
		return (1);
	content->map_copy = NULL;
	return (0);
}
