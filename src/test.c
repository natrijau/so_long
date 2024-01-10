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

int     check_map(map_texture_t *content, int line, int col)
{
    int i;
    int j;

    i = 1;
    j = 1;
   /* 
    printf("\nQQQ\n");
    for (int c = 1; c <= line; c++)
        printf("%s\n",content->map[c]);
    printf("QQQ\n");
*/
    while (i < line)
    {
        if (!(content->map[i][j] == '1' || content->map[i][j] == 'V'))
        {
            printf("map impossible a faire !\n");
            return (1);
        }
        if (j == col)
        {
            printf("\n");
            i++;
        }
        else
            j++;
    }
    printf("map ok !\n");
    return (0);
}

void     check_if_resolvable(map_texture_t *content, int x, int y, int line, int col)
{
    map_texture_t *copie;

    copie = content;
    if (copie->map[x][y] != '1' && copie->map[x][y] != 'V')
    {
       copie->map[x][y] = 'V';
       check_if_resolvable(copie, x + 1, y, line, col);
       check_if_resolvable(copie, x - 1, y, line, col);
       check_if_resolvable(copie, x, y + 1, line, col);
       check_if_resolvable(copie, x, y - 1, line, col);
    }
    else 
        return ;
    check_map(copie, line, col);
}

int     test_in_map(int line, int column, map_texture_t *content)
{
    int i;
    int j;
    int collectible;
    int player;
    int exit;
    int x;
    int y;

    x = 0;
    y = 0; 
    collectible = 0;
    player = 0;
    exit = 0; 
    i = 1;
    j = 1;
    
    while (i <= line)
    {
        if ((((((content->map[i][j] != '1' && content->map[i][j] != 'E') 
            && content->map[i][j] != '0')) && content->map[i][j] != 'P') && content->map[i][j] != 'C'))
        {
            printf("erreur\n");
            return (1);
            break;
        }
        if (content->map[i][j] == 'C')
            collectible++;
        if (content->map[i][j] == 'E')
            exit++;
        if (content->map[i][j] == 'P')
        {
            player++;
            x = i;
            y = j;
        }
        j++;
        if (j == column)
        {
            i++;
            printf("\n");
            j = 1;
        }
    }
    if (player != 1 || exit != 1 || collectible != 1)    
    {
        printf("Erreur sur le nombre de player ou de sortie\n");
        return (1);
    }
    
    check_if_resolvable(content, x, y, line, column);
    return (0);
}

//cheque si contour de map ok
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
    test_in_map(count_line,count_column,content);
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
