/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:34:24 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/23 13:32:09 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../definitive_libft/get_next_line.h"
#include "../definitive_libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#include "./parsing_map.h"
#include "./main.h"

t_map_texture	*init_map(t_map_texture *content)
{
	while (content->get_map->tmp)
	{
		content->get_map->str = ft_strjoin(content->get_map->str,
				content->get_map->tmp);
		if (content->get_map->str == NULL)
		{
			free(content);
			exit(EXIT_FAILURE);
		}
		free(content->get_map->tmp);
		content->get_map->tmp = get_next_line(content->get_map->byte);
	}
	content->map = ft_split(content->get_map->str, '\n');
	free(content->get_map->str);
	if (content->map == NULL)
	{
		free_map(content->map);
		exit(EXIT_FAILURE);
	}
	close(content->get_map->byte);
	return (content);
}

//Get map
int	get_map(char *av, t_map_texture *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	data->get_map = map;
	map->byte = open(av, O_RDWR);
	if (map->byte == -1)
		return (-1);
	map->str = get_next_line(map->byte);
	if (map->str == NULL)
	{
		free(map->str);
		close(map->byte);
		//free(map);
		// mlx_terminate(data->mlx);
		// free(data);
		return (1);
	}
	map->tmp = get_next_line(map->byte);
	return (0);
}

//Check format
int	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (((str[i - 1] == 'r') && (str[i - 2] == 'e'))
		&& ((str[i - 3] == 'b') && (str[i - 4] == '.')))
		return (0);
	else
	{
		ft_putstr_fd("Le format de la map n'est pas bon !\n", 2);
		return (1);
	}
}

//Check numb of arg and ber
int	check_arg(int ac, char *av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Le nombre d'argument n'est pas valide !\n", 2);
		return (1);
	}
	else if (check_ber(av) == 1)
		return (1);
	return (0);
}
