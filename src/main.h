#ifndef MAIN_H
# define MAIN_H


typedef struct s_player
{
	mlx_image_t *mouse;
    int         x;
    int         y;
} player_t;

typedef struct s_texture
{
	mlx_image_t *img;
	mlx_image_t *laine;
	mlx_image_t *collectible;
	mlx_image_t *murs;
	mlx_image_t *sol;
	mlx_image_t *exit;
    int x;
    int y;
}   texture_t;

//a modifier en game_t
typedef struct s_map_texture
{
	mlx_image_t 	*mouse;
	mlx_t           *mlx;
    texture_t       *texture;
   // player_t        *mouse;
    char            **map;
    int             x;
    int             y;
}   map_texture_t;

#endif
