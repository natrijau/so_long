/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:09:54 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/19 17:01:01 by natrijau         ###   ########.fr       */
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

// //Load images
// void	load_file(void)
// {
// 	mlx_texture_t	*texture;
// 	mlx_texture_t	*img_laine;
// 	mlx_texture_t	*wall;
// 	mlx_texture_t	*herbe;
// 	mlx_texture_t	*blackhole;

// 	texture = mlx_load_png("./remus.png");
// 	if (!texture)
// 		error();
// 	img_laine = mlx_load_png("./laine.png");
// 	if (!img_laine)
// 		error();
// 	wall = mlx_load_png("./arbres.png");
// 	if (!wall)
// 		error();
// 	herbe = mlx_load_png("./herbe.png");
// 	if (!herbe)
// 		error();
// 	blackhole = mlx_load_png("./blackhole.png");
// 	if (!blackhole)
// 		error();
// }

//Laying textures
mlx_image_t	*put_texture(mlx_t *mlx, char *path, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	image = mlx_texture_to_image(mlx, texture);
	if (!(image))
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, y, x) < 0)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	mlx_delete_texture(texture);
	return (image);
}

//Coordinates images
t_map_texture	*images_in_map(t_map_texture *content, int x, int y)
{
	t_texture *images;
	
	images = ft_calloc(sizeof(t_texture), 1);
	if (!images)
		return (NULL);
	if (content->map[x][y] == '1')
		images->wall = put_texture(content->mlx, "./arbres.png", x * 64, y * 64);
	else if (content->map[x][y] != '1')
		images->floor = put_texture(content->mlx, "./herbe.png", x * 64, y * 64);
	if (content->map[x][y] == 'P')
	{
		content->y = y;
		content->x = x;
	}
	if (content->map[x][y] == 'C')
		images->collectible = put_texture(content->mlx, "./laine.png", x * 64, y * 64);
	if (content->map[x][y] == 'E')
		images->exit = put_texture(content->mlx, "./blackhole.png", x * 64, y * 64);
	content->texture = images;
	free(images->collectible);
	free(images->wall);
	free(images->floor);
	free(images->exit);
	free(images);
	return (content);
}

//Display images
void	display_image(t_map_texture *content, mlx_texture_t *texture)
{
	int	x;
	int	y;

	x = 0;
	(void)texture;
	while (content->map[x])
	{
		y = -1;
		while (content->map[x][++y])
			content = images_in_map(content, x, y);
		x++;
	}
	if (mlx_image_to_window(content->mlx, content->player,
			content->y * 64, content->x * 64) < 0)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	mlx_delete_texture(texture);
}
