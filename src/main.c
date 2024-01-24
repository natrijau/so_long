/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:04 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/24 14:08:54 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	convert_and_display(t_map_texture *content, mlx_texture_t *texture)
{
	content->player = mlx_texture_to_image(content->mlx, texture);
	if (!content->player)
		exit(EXIT_FAILURE);
	display_image(content, texture);
	content->moves = 0;
	content->compte_collectible = 0;
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
		free(content);
		content = NULL;
		return (EXIT_FAILURE);
	}
	return (0);
}

int	get_and_open(char *str, t_map_texture *content)
{
	if (get_map(str, content) != 0)
	{
		free(content->get_map);
		free(content);
		content = NULL;
		ft_putstr_fd("Erreur lors de la lecture de la map !\n", 2);
		return (1);
	}
	content = init_map(content);
	if (check_size(content) != 0)
	{
		free_map(content->map);
		free(content->get_map);
		free(content);
		content = NULL;
		return (1);
	}
	open_window(content);
	return (0);
}

int	main(int ac, char **av)
{
	t_map_texture	*content;
	mlx_texture_t	*texture;

	if (check_arg(ac, av[1]) != 0)
		return (EXIT_SUCCESS);
	content = malloc(sizeof(t_map_texture));
	if (!content)
		return (0);
	if (get_and_open(av[1], content) != 0)
		return (0);
	texture = mlx_load_png("./remus.png");
	if (!texture)
	{
		free_map(content->map);
		return (0);
	}
	convert_and_display(content, texture);
	mlx_key_hook(content->mlx, (void (*))ft_hook, content);
	mlx_loop(content->mlx);
	free_final(content);
	return (EXIT_SUCCESS);
}
