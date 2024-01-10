/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:34:04 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/10 13:11:26 by natrijau         ###   ########.fr       */
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
#include "./parsing_map.c"
#include "./main.h"
#define WIDTH  1200
#define HEIGHT 1200

// typedef struct mouse_img
// {
//     mlx_image_t *mouse;

// } mouse_img_t;

// typedef struct player
// {
//     mlx_t       *mlx;
//     mouse_img_t *player;
// } player_t;

// typedef struct collectible
// {
//     mlx_t       *mlx;
//     mlx_image_t *collectible;
// } collectible_t;

// typedef struct textures
// {
//     mlx_t       *mlx;
//     mlx_image_t *map_texture;
// }   texture_t;

// typedef struct map_texture
// {
//     collectible_t   *laine;
//     texture_t       *walls_grass;
//     player_t        *mouse;
//     char            **map;
//     int             x;
//     int             y;
// }   map_texture_t;
// int     check_map(map_texture_t *content, int line, int col)
// {
//     int i;
//     int j;

//     i = 1;
//     j = 1;
//     while (i < line)
//     {
//         if (!(content->map[i][j] == '1' || content->map[i][j] == 'V'))
//         {
//             printf("map impossible a faire !\n");
//             //free(copie);
//             return (1);
//         }
//         if (j == col)
//         {
//             //printf("\n");
//             i++;
//         }
//         else
//             j++;
//     }
//     printf("map ok !");
//     //free(copie);
//     return (0);
// }

// void     check_if_resolvable(map_texture_t *copie, int x, int y, int line, int col)
// {
    
// //    printf("\n");
//     printf("x%d et y%d\n", x, y);
//     for(int c = 0; c <= line + 1;c++)
//         printf("%s\n",copie->map[c]);
//     if (copie->map[x][y] != '1' && copie->map[x][y] != 'V')
//     {
//        copie->map[x][y] = 'V';
//        check_if_resolvable(copie, x + 1, y, line, col);
//        check_if_resolvable(copie, x - 1, y, line, col);
//        check_if_resolvable(copie, x, y + 1, line, col);
//        check_if_resolvable(copie, x, y - 1, line, col);
//     }
//     else 
//         return ;
    
//     check_map(copie, line, col);
// }

// map_texture_t    *copie_content(map_texture_t *copie, map_texture_t *content, int line)
// {
//     int i;

//     i = 0;
//     copie->map = malloc(sizeof(char *) * line + 1);
//     if (!copie)
//         return(NULL);
//     while (i <= line + 1)
//     {
//         copie->map[i] = ft_strdup(content->map[i]);
//         //printf("%s\n",copie->map[i]);
//         i++;
//     }
//     //for(int c = 0; c <= line + 1;c++)
//     //    printf("%s\n",copie->map[c]);
//     //printf("\n");
//     return (copie);
// }

// int     test_in_map(int line, int column, map_texture_t *content)
// {
//     int i;
//     int j;
//     int collectible;
//     int player;
//     int exit;
//     //int x;
//     //int y;
//     map_texture_t *copie;
//     copie = malloc(sizeof(map_texture_t));

//     content->x = 0;
//     content->y = 0; 
//     collectible = 0;
//     player = 0;
//     exit = 0; 
//     i = 1;
//     j = 1;
    
//     while (i <= line)
//     {
//         if ((((((content->map[i][j] != '1' && content->map[i][j] != 'E') 
//             && content->map[i][j] != '0')) && content->map[i][j] != 'P') && content->map[i][j] != 'C'))
//         {
//             printf("erreur\n");
//             return (1);
//             break;
//         }
//         if (content->map[i][j] == 'C')
//             collectible++;
//         if (content->map[i][j] == 'E')
//             exit++;
//         if (content->map[i][j] == 'P')
//         {
//             player++;
//             content->x = i;
//             content->y = j;
//         }
//         j++;
//         if (j == column)
//         {
//             i++;
//             //printf("\n");
//             j = 1;
//         }
//     }
    
//     if (player != 1 && exit != 1 && collectible > 0)    
//     {
//         printf("p = %d, e = %d, c = %d\n", player, exit, collectible);
//         printf("Erreur sur le nombre de player ou de sortie\n");
//         return (1);
//     }
//     copie = copie_content(copie, content, line); 
//     check_if_resolvable(copie, content->x, content->y, line, column);
//     return (0);
// }

// //cheque si contour de map ok
// int     check_walls(map_texture_t *content)
// {
//     int i;
//     int j;
//     int count_column;
//     int count_line;

//     count_line = 0;
//     i = 0;
//     j = 0;
//     count_column = ft_strlen(content->map[i]) - 1;

//     while (content->map[0][j])
//     {
//         if (content->map[0][j] != '1')
//         {
//             printf("erreur mur premiere ligne\n");
//             return (1);
//             break;
//         }
//         j++;
//     }

// //Nombre de ligne
//     while (content->map[i])
//         i++;

//     count_line = i - 2;
//     j = 0;

//     while (content->map[i - 1][j])
//     {
//         if (content->map[i - 1][j] != '1')
//         {
//             printf("erreur mur derniere ligne\n");
//             return (1);
//             break;
//         }
//         j++;
//     }
//     i = 1;
//     while (i <= count_line)
//     {
//         if (content->map[i][0] != '1' || content->map[i][count_column] != '1')
//         {
//             printf("erreur mur premiere ou derniere colonne\n");
//             return (1);
//             break;
//         }
//         i++;
//     }
//     test_in_map(count_line,count_column,content);
//     return (0);
// }
static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(/*void *param, */map_texture_t *data)
{
    //player_t *params;
    //params = (player_t *)param;
    //printf("x%d, y%d, ",map->x,map->y);
    //(void)map;
    //for(int c = 0;map->map[c];c++)
        //printf("%s",map->map[0]);
    if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
    {
        mlx_close_window(data->mlx);
    }

	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
        data->mouse->instances[0].y -= 64;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
        data->mouse->instances[0].y += 64;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
        data->mouse->instances[0].x -= 64;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
        data->mouse->instances[0].x += 64;

}

/*
void my_keyhook(mlx_key_data_t keydata, mouse_img_t *player)
{
    

	// If we PRESS the 'W' key, move top.

	// If we RELEASE the 'A' key, move left.
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)

	// If we HOLD the 'S' move bottom.
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)

	// If we HOLD the 'D' move right.
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)

}
*/


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

    //content->map = content;
    //for (int c = 0;content->map[c]; c++)
    //    printf("%s\n",content->map[c]);
    return (content);
    /*
    for (int c = 0; c < 4; c++)
        printf("%s\n",content->map[c]);
    free_map(content->map);
    free(content);*/
}




//int get_map(char **str)
//{
//    char *str;
//    char *tmp;
//    int byte;
//    byte = open(str, O_RDWR);
//
//    if (byte == -1)
//        return (-1);
//    str = get_next_line(byte);
//    if (str == NULL)
//    {
//        free(str);
//        close(byte);
//        return (-1);
//    }
//    tmp = get_next_line(byte);
//    init_map(tmp, str, byte);
//    return (0);
//}

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

int	main(int ac, char **av)
{

	// Print the window width and height.
	//mlx_t* mlx;
    //texture_t *player;
    //player_t    params;

    //player = malloc(sizeof(texture_t));
    
    (void) ac;
    (void) av;

    //texture_t       *images;
    map_texture_t *content;
    content = malloc(sizeof(map_texture_t));
    //images = malloc(sizeof(texture_t));
    //content->texture = images;
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

    check_walls(content);
    //Initialisez et exécutez une nouvelle instance de fenêtre.
	if (!(content->mlx = mlx_init(WIDTH, HEIGHT, "The cat game", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
   // load_file();
    // //Fonction appart
    // // Try to load the file
	 mlx_texture_t* texture = mlx_load_png("./64_64.cat.png");
	 if (!texture)
         error();
	// mlx_texture_t* img_laine = mlx_load_png("./laine.png");
	// if (!img_laine)
    //     error();
    //    	mlx_texture_t* wall = mlx_load_png("./arbres.png");
	// if (!wall)
    //     error();
	// mlx_texture_t* herbe = mlx_load_png("./herbe.png");
	// if (!herbe)
    //     error();
    //     mlx_texture_t* blackhole = mlx_load_png("./blackhole.png");
	// if (!blackhole)
    //     error();

	// Convert texture to a displayable image
    content->mouse = mlx_texture_to_image(content->mlx, texture);
	if (!content->mouse)
        error();
    /*
    laine = mlx_texture_to_image(mlx, img_laine);
	if (!laine)
        error();
     murs = mlx_texture_to_image(mlx, wall);
	if (!wall)
        error();   
     sol = mlx_texture_to_image(mlx, herbe);
	if (!herbe)
        error(); 
     exit = mlx_texture_to_image(mlx, blackhole);
	if (!laine)
        error(); 
    player = malloc(sizeof(mouse_img_t));
    player->mouse = img;
*/
	// Display the image
    int x = 0;
    int y = 0;
    int ord = 0;
    int abs = 0;
    while (content->map[x])
    {
        y = 0;
        while (content->map[x][y])
        {
            if (content->map[x][y] == '1')
                put_texture(content->mlx, "./arbres.png", x * 64, y * 64);
               // mlx_image_to_window(mlx, murs, y * 64 , x * 64);
            else if (content->map[x][y] == '0' || content->map[x][y] == 'C' 
                        || content->map[x][y] == 'P' || content->map[x][y] == 'E')
                put_texture(content->mlx, "./herbe.png", x * 64, y * 64);
                //mlx_image_to_window(mlx, sol, y * 64 , x * 64);
            if (content->map[x][y] == 'P')
            {
                abs = y;
                ord = x;
            }
             if (content->map[x][y] == 'C')
            {
                //mlx_image_to_window(mlx, laine, y * 64, x * 64);
                put_texture(content->mlx, "./laine.png", x * 64, y * 64);
            } 
             if (content->map[x][y] == 'E')
                //mlx_image_to_window(mlx, exit, y * 64, x * 64);  
                put_texture(content->mlx, "./blackhole.png", x * 64, y * 64);
            y++;
        }
        x++;
    }
    
    if (mlx_image_to_window(content->mlx, content->mouse, abs * 64, ord * 64) < 0)
        error();

    //player->mlx = mlx;
    //player->mouse = mouse;

    //Gardez la fenêtre ouverte tant qu'un arrêt n'est pas demandé.
    mlx_loop_hook(content->mlx, (void (*))ft_hook, content);
	mlx_loop(content->mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(content->mlx, content->mouse);
    free(content->texture);
    //Détruisez et nettoyez toutes les images et ressources mlx.
	mlx_terminate(content->mlx);

	return (EXIT_SUCCESS);
}
