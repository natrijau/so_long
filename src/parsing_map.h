#ifndef PARSING_MAP_H
# define PARSING_MAP_H

#include "./main.h"

map_texture_t	*copie_content(map_texture_t *copie, map_texture_t *content, int line);
int				check_map(map_texture_t *content, int line, int col);
void			check_if_resolvable(map_texture_t *copie, int x, int y, int line, int col);
int				test_in_map(int line, int column, map_texture_t *content);
int				check_walls(map_texture_t *content);
int				check_size(map_texture_t *content);
#endif