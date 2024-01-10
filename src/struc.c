/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:57:11 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/09 11:42:45 by natrijau         ###   ########.fr       */
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
#define WIDTH  1200
#define HEIGHT 1200

typedef struct map
{
    mlx_t   *mlx;
    char    **map;
} map_t;

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

void    test()
{
    map_t *content;

    content = malloc(sizeof(map_t));
    
    for (int c = 0;content->map[c]; c++)
        printf("%s\n",content->map[c]);
}

map_t    *init_map(char *tmp, char *str, int fd)
{
    map_t *content;

    content = malloc(sizeof(map_t));
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
    content = content.map;
    return (content);
    /*
    for (int c = 0; c < 4; c++)
        printf("%s\n",content->map[c]);
    free_map(content->map);
    free(content);*/
}

int main()
{
    map_t  *content;

    content = malloc(sizeof(map_t));
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
}
