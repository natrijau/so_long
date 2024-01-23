/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:09:54 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/23 17:04:22 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../definitive_libft/get_next_line.h"
#include "../definitive_libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#include "./main.h"

//Laying textures
mlx_image_t	*put_texture(mlx_t *mlx, char *path, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		exit(EXIT_FAILURE);
	}
	image = mlx_texture_to_image(mlx, texture);
	if (!(image))
	{
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, y, x) < 0)
	{
		exit(EXIT_FAILURE);
	}
	mlx_delete_texture(texture);
	return (image);
}

//Coordinates images
void	images_in_map(t_map_texture *content, int x, int y)
{
	content->texture = ft_calloc(sizeof(t_texture), 1);
	if (!content->texture)
		return ;
	if (content->map[x][y] == '1')
		content->texture->wall = put_texture(content->mlx,
				"./arbres.png", x * 64, y * 64);
	else if (content->map[x][y] != '1')
		content->texture->floor = put_texture(content->mlx,
				"./herbe.png", x * 64, y * 64);
	if (content->map[x][y] == 'P')
	{
		content->y = y;
		content->x = x;
	}
	if (content->map[x][y] == 'C')
		content->texture->collectible = put_texture(content->mlx,
				"./laine.png", x * 64, y * 64);
	if (content->map[x][y] == 'E')
		content->texture->exit = put_texture(content->mlx,
				"./blackhole.png", x * 64, y * 64);
	free(content->texture);
}

//Display images
void	display_image(t_map_texture *content, mlx_texture_t *texture)
{
	int	x;
	int	y;

	x = 0;
	while (content->map[x])
	{
		y = 0;
		while (content->map[x][y])
		{
			images_in_map(content, x, y);
			y++;
		}
		x++;
	}
	if (mlx_image_to_window(content->mlx, content->player,
			content->y * 64, content->x * 64) < 0)
	{
		exit(EXIT_FAILURE);
	}
	mlx_delete_texture(texture);
}
