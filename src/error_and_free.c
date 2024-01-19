/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:32:34 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/19 16:40:11 by natrijau         ###   ########.fr       */
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

int	exit_game(t_map_texture *content)
{
/// a effacer
	// free(content->get_map);
	int	i = 0;
	while (content->map[i])
	{
		free(content->map[i]);
		i++;
	}
	free(content->map);
	mlx_delete_image(content->mlx, content->player);
	mlx_terminate(content->mlx);
	free(content);
	return (EXIT_SUCCESS);
}

void	free_final(t_map_texture *content)
{
	free(content->get_map);
	free_map(content->map);
	// mlx_delete_image(content->mlx, content->texture->collectible);
	// mlx_delete_image(content->mlx, content->texture->exit);
	// mlx_delete_image(content->mlx, content->texture->wall);
	// mlx_delete_image(content->mlx, content->texture->floor);
	// free(content->texture->collectible);
	// free(content->texture->exit);
	// free(content->texture->wall);
	// free(content->texture->floor);
	free(content->texture);
	mlx_terminate(content->mlx);
	free(content);
	
}

//Fction error
void	error(void)
{
	// puts(mlx_strerror(mlx_errno));
	
	exit(EXIT_FAILURE);
}

void	free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// void	free_map2(t_map_texture *data)
// {
	// free(data->get_map->str);
	// free(data->get_map->tmp);
	// free(data->get_map);
// }
