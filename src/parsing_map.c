#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../definitive_libft/get_next_line.h"
#include "../definitive_libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#include "./main.h"


//! coin manquant 
//! largeur pas bonne

map_texture_t    *copie_content(map_texture_t *copie, map_texture_t *content, int line)
{
	int i;

	i = 0;
	line += 1;
	copie->map = malloc(sizeof(char *) * line + 1);
	if (!copie)
		return(NULL);
	while (i <= line)
	{
		copie->map[i] = ft_strdup(content->map[i]);
		i++;
	}
	copie->map[i] = NULL;
	return (copie);
}

//Check si flood fil valid
int     check_map(map_texture_t *content, int line, int col)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < line)
	{
		if (!(content->map[i][j] == '1' || content->map[i][j] == 'V' || content->map[i][j] == '0'))
		{
			printf("map impossible a faire !\n");
			//free(copie);
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
	//free(copie);
	return (0);
}

//Flood_fil
map_texture_t	*check_if_resolvable(map_texture_t *copie, int x, int y, int line, int col)
{

	if (copie->map[x][y] != '1' && copie->map[x][y] != 'V')
	{
	   copie->map[x][y] = 'V';
	   check_if_resolvable(copie, x + 1, y, line, col);
	   check_if_resolvable(copie, x - 1, y, line, col);
	   check_if_resolvable(copie, x, y + 1, line, col);
	   check_if_resolvable(copie, x, y - 1, line, col);
	}
	return (copie);
}

//Test le contenue de la map
int     test_in_map(int line, int column, map_texture_t *content)
{
	int i;
	int j;
	int player;
	int exit;
	map_texture_t *copie;
	copie = malloc(sizeof(map_texture_t));

	content->x = 0;
	content->y = 0; 
	content->collectible = 0;
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
			content->collectible++;
		if (content->map[i][j] == 'E')
			exit++;
		if (content->map[i][j] == 'P')
		{
			player++;
			content->x = i;
			content->y = j;
		}
		j++;
		if (j == column)
		{
			i++;
			printf("\n");
			j = 1;
		}
	}
	
	if (player != 1 || exit != 1 || content->collectible < 1)    
	{
		printf("p = %d, e = %d, c = %d\n", player, exit, content->collectible);
		printf("Erreur sur le nombre de player ou de sortie\n");
		return (1);
	}
	copie = copie_content(copie, content, line);
	copie = check_if_resolvable(copie, content->x, content->y, line, column);
	check_map(copie, line, column);
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

int	check_size(map_texture_t *content)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
    while (content->map[i])
    {
		c = 0;
        while (content->map[0][j])
            j++;
		while (content->map[i][c])
			c++;
		if (c != j)
		{
			printf("le nombre de colonnes ne correspond pas!");
			return(1);
		}		
        i++;
    }
	return (check_walls(content));
}
