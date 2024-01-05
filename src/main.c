#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../definitive_libft/get_next_line.h"
#include "../definitive_libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#define WIDTH  1200
#define HEIGHT 1200

typedef struct mouse_img
{
    mlx_image_t *mouse;

} mouse_img_t;

typedef struct player
{
    mlx_t       *mlx;
    mouse_img_t *player;
} player_t;

typedef struct collectible
{
    mlx_t       *mlx;
    mlx_image_t *collectible;
} collectible_t;

typedef struct textures
{
    mlx_t       *mlx;
    mlx_image_t *map_texture;
}   texture_t;

typedef struct map_texture
{
    collectible_t   *laine;
    texture_t       *walls_grass;
    player_t        *mouse;
    char            **map;
}   map_texture_t;

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void *param)
{
    player_t *params;

    params = (player_t *)param;
    // close window with escp
    if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
    {
        mlx_close_window(params->mlx);
    }
	if (mlx_is_key_down(params->mlx, MLX_KEY_W))
        params->player->mouse->instances[0].y -= 32;
	else if (mlx_is_key_down(params->mlx, MLX_KEY_S))
        params->player->mouse->instances[0].y += 32;
	else if (mlx_is_key_down(params->mlx, MLX_KEY_A))
        params->player->mouse->instances[0].x -= 32;
	else if (mlx_is_key_down(params->mlx, MLX_KEY_D))
        params->player->mouse->instances[0].x += 32;
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
/*//cheque si map ok
int     check_walls(void)
{
    map_texture_t *content;
    content = init_map();

    printf()
}*/

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
    /*
    for (int c = 0; c < 4; c++)
        printf("%s\n",content->map[c]);
    free_map(content->map);
    free(content);*/
}

int get_map(void)
{
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
    init_map(tmp, str, byte);
    return (0);
}

int32_t	main(void)
{
	// Print the window width and height.
	mlx_t* mlx;
    mlx_image_t *img;
    mlx_image_t *laine;
    mouse_img_t *player;
    player_t    params;

    
    //Initialisez et exécutez une nouvelle instance de fenêtre.
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "The cat game", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

    // Try to load the file
	mlx_texture_t* texture = mlx_load_png("./64_64.cat.png");
	if (!texture)
        error();
	mlx_texture_t* img_laine = mlx_load_png("./laine.png");
	if (!img_laine)
        error();

	// Convert texture to a displayable image
    img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();
    laine = mlx_texture_to_image(mlx, img_laine);
	if (!laine)
        error();
    player = malloc(sizeof(mouse_img_t));
    player->mouse = img;

	// Create a new image
//	mlx_image_t* image = mlx_new_image(mlx, 64, 64);
//	mlx_image_t* img_mur_top = mlx_new_image(mlx, 512, 64);
	//if (!img)
	//	error();

	// Set every pixel to white
//	memset(img_mur_left->pixels, 255, img_mur_left->width * img_mur_left->height * sizeof(int32_t));
//	memset(img_mur_top->pixels, 255, img_mur_top->width * img_mur_top->height * sizeof(int32_t));

	// Display the image
	if (mlx_image_to_window(mlx, player->mouse, 64, 128) < 0)
        error();
	if (mlx_image_to_window(mlx, laine, 128, 128) < 0)
        error();
	//if (mlx_image_to_window(mlx,img_mur_top, 0, 0) < 0)
    //    error();
    params.mlx = mlx;
    params.player = player;

    //Gardez la fenêtre ouverte tant qu'un arrêt n'est pas demandé.
    mlx_loop_hook(mlx, (void *)ft_hook, &params);
	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, player->mouse);
    free(player);
    //Détruisez et nettoyez toutes les images et ressources mlx.
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}
