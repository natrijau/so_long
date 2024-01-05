#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../definitive_libft/get_next_line.h"
#include "../definitive_libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#define WIDTH  1320
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

//cheque si map ok
int     check_walls(map_texture_t *content)
{
    int i;
    int j;
    int count_column;
    int count_line;

    count_line = 0;
    i = 0;
    j = 0;
    count_column = ft_strlen(content->map[i]) - 1;

    while (content->map[0][j])
    {
        if (content->map[0][j] != '1')
        {
            printf("erreur mur premiere ligne\n");
            return (1);
            break;
        }
        j++;
    }

//Nombre de ligne
    while (content->map[i])
        i++;

    count_line = i - 2;
    j = 0;

    while (content->map[i - 1][j])
    {
        if (content->map[i - 1][j] != '1')
        {
            printf("erreur mur derniere ligne\n");
            return (1);
            break;
        }
        j++;
    }
    i = 1;
    while (i <= count_line)
    {
        if (content->map[i][0] != '1' || content->map[i][count_column] != '1')
        {
            printf("erreur mur premiere ou derniere colonne\n");
            return (1);
            break;
        }
        i++;
    }

    //contour map ok
    for (int c = 0; c < 4; c++)
        printf("%s\n",content->map[c]);
    return (0);
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
    
    check_walls(content);

    return (content);
    /*
    for (int c = 0; c < 4; c++)
        printf("%s\n",content->map[c]);
    free_map(content->map);
    free(content);
    */
}

int main()
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
