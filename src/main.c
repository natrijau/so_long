/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:04 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/10 16:59:03 by natrijau         ###   ########.fr       */
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

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(map_texture_t *data)
{
    printf("caract %i\n",data->x);
    if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(data->mlx);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W)/* && data->map[y - 1][x] != '1'*/)
        data->player->instances[0].y -= 64;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
        data->player->instances[0].y += 64;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
        data->player->instances[0].x -= 64;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
        data->player->instances[0].x += 64;

}
void    free_map(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

map_texture_t    *init_map(char *tmp, char *str, int fd)
{
    map_texture_t *content;

    content = malloc(sizeof(map_texture_t));
    while (tmp)
    {
        str = ft_strjoin(str, tmp);
        if (str == NULL)
        {
            free(content);
            exit(EXIT_FAILURE);
        }
        free(tmp);
        tmp = get_next_line(fd);
    }
    content->map = ft_split(str, '\n');
    if (content->map == NULL)
    {
        free_map(content->map);
        exit(EXIT_FAILURE);
    }
    free(str);
    close(fd);
    return (content);
}

void load_file(void)
{
	mlx_texture_t* texture = mlx_load_png("./64_64.cat.png");
	if (!texture)
        error();
	mlx_texture_t* img_laine = mlx_load_png("./laine.png");
	if (!img_laine)
        error();
       	mlx_texture_t* wall = mlx_load_png("./arbres.png");
	if (!wall)
        error();
	mlx_texture_t* herbe = mlx_load_png("./herbe.png");
	if (!herbe)
        error();
    mlx_texture_t* blackhole = mlx_load_png("./blackhole.png");
	if (!blackhole)
        error();    
}

//fonction qui pose une texture
void    put_texture(mlx_t *mlx, char *path, int x, int y)
{
    mlx_texture_t    *texture;
    mlx_image_t        *image;

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
    return ;
}

int    open_window(map_texture_t *content)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (content->map[i])
    {
        while (content->map[0][j])
            j++;
        i++;
    }
	if (!(content->mlx = mlx_init(j * 64, i * 64, "The cat game", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
    return (0);
}
int	main(int ac, char **av)
{
    (void) ac;
    (void) av;

    map_texture_t *content;
    content = malloc(sizeof(map_texture_t));
    char *str;
    char *tmp;
    int byte;

    byte = open("./src/map.ber", O_RDWR);
    if (byte == -1)
        return (-1);
    str = get_next_line(byte);
    if (str == NULL)
    {
        free(str);
        close(byte);
        return (-1);
    }
    tmp = get_next_line(byte);
    content = init_map(tmp, str, byte);
    
    if (check_size(content) == 0)
        open_window(content);
    else 
        return (EXIT_FAILURE);
   // load_file();
    // //Fonction appart
    // // Try to load the file
	 mlx_texture_t* texture = mlx_load_png("./64_64.cat.png");
	 if (!texture)
         error();
	// Convert texture to a displayable image
    content->player = mlx_texture_to_image(content->mlx, texture);
	if (!content->player)
        error();
	// Display the image
    int x = 0;
    int y = 0;
    // int ord = 0;
    // int abs = 0;
    while (content->map[x])
    {
        y = 0;
        while (content->map[x][y])
        {
            if (content->map[x][y] == '1')
                put_texture(content->mlx, "./arbres.png", x * 64, y * 64);
            else if (content->map[x][y] == '0' || content->map[x][y] == 'C' 
                        || content->map[x][y] == 'P' || content->map[x][y] == 'E')
                put_texture(content->mlx, "./herbe.png", x * 64, y * 64);
            if (content->map[x][y] == 'P')
            {
                content->y = y;
                content->x = x;
            }
             if (content->map[x][y] == 'C')
                put_texture(content->mlx, "./laine.png", x * 64, y * 64);
             if (content->map[x][y] == 'E')
                put_texture(content->mlx, "./blackhole.png", x * 64, y * 64);
            y++;
        }
        x++;
    }
    
    if (mlx_image_to_window(content->mlx, content->player, content->y * 64, content->x * 64) < 0)
        error();

    //Gardez la fenêtre ouverte tant qu'un arrêt n'est pas demandé.
    mlx_loop_hook(content->mlx, (void (*))ft_hook, content);
	mlx_loop(content->mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(content->mlx, content->player);
    free(content->texture);
    //Détruisez et nettoyez toutes les images et ressources mlx.
	mlx_terminate(content->mlx);

	return (EXIT_SUCCESS);
}
