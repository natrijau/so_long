/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:04 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/12 17:57:01 by natrijau         ###   ########.fr       */
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
#include "./parsing_map.h"
#include "./main.h"
#define WIDTH  1200
#define HEIGHT 1200

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

//Open window
int	open_window(t_map_texture *content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (content->map[i])
	{
		while (content->map[0][j])
			j++;
		i++;
	}
	content->mlx = mlx_init(j * 64, i * 64, "REMUS GAME", false);
	if (!(content->mlx))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
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
		printf("Le format de la map n'est pas bon !\n");
		return (1);
	}
}

//Get tab map
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
	if (content->map == NULL)
	{
		free_map(content->map);
		exit(EXIT_FAILURE);
	}
	free(content->get_map->str);
	close(content->get_map->byte);
	return (content);
}
//Get map
int	get_map(char *av, t_map_texture *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	//protection malloc
	// free map 
	data->get_map = map;
	map->byte = open(av, O_RDWR);
	if (map->byte == -1)
		return (-1);
	map->str = get_next_line(map->byte);
	if (map->str == NULL)
	{
		free(map->str);
		close(map->byte);
		return (-1);
	}
	map->tmp = get_next_line(map->byte);
	return (0);
}
//Check numb of arg and ber
int	check_arg(int ac, char *av)
{
	if (ac != 2)
	{
		printf("Le nombre d'argument n'est pas valide !\n");
		//erreur nombre dargument --> return 4
		return (4);
	}
	else if (check_ber(av) == 1)
	{
		//erreur pas .ber --> return 5
		return (5);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map_texture	*content;
	mlx_texture_t	*texture;

	if (check_arg(ac, av[1]) != 0)
		return (EXIT_SUCCESS);
	content = malloc(sizeof(t_map_texture));
	//protection malloc
	if (get_map(av[1], content) != 0)
	{
		free(content->get_map);
		free(content);
		printf("Erreur lors de la lecture de la map !\n");
		return (EXIT_SUCCESS);
	}
	content = init_map(content);
	if (check_size(content) != 0)
		return (EXIT_FAILURE);
	open_window(content);
	texture = mlx_load_png("./remus.png");
	if (!texture)
		error();
	// Convert texture to a displayable image
	content->player = mlx_texture_to_image(content->mlx, texture);
	if (!content->player)
		error();
	display_image(content);
	//Gardez la fenêtre ouverte tant qu'un arrêt n'est pas demandé.
	content->moves = 0;
	content->compte_collectible = 0;
	mlx_key_hook(content->mlx, (void (*))ft_hook, content);
	mlx_loop(content->mlx);
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(content->mlx, content->player);
	free(content->texture);
	//Détruisez et nettoyez toutes les images et ressources mlx.
	mlx_terminate(content->mlx);
	return (EXIT_SUCCESS);
}
