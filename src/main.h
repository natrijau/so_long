/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:35:25 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/24 16:15:53 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../definitive_libft/get_next_line.h"
# include "../definitive_libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

typedef struct s_texture
{
	mlx_image_t	*collectible;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
}	t_texture;

typedef struct s_map
{
	char	*str;
	char	*tmp;
	int		byte;
}	t_map;

typedef struct s_map_texture
{
	mlx_image_t		*player;
	mlx_t			*mlx;
	t_texture		*texture;
	t_map			*get_map;
	char			**map;
	char			**map_copy;
	int				i;
	int				j;
	int				x;
	int				y;
	int				collectible;
	int				exit;
	int				the_player;
	int				compte_collectible;
	int				moves;
	int				width;
	int				height;
}	t_map_texture;

mlx_image_t		*put_texture(mlx_t *mlx, char *path, int x, int y);
t_map_texture	*init_map(t_map_texture *content);
mlx_image_t		*put_texture(mlx_t *mlx, char *path, int x, int y);
void			images_in_map(t_map_texture *content, int x, int y);
void			load_file(void);
void			display_image(t_map_texture *content, mlx_texture_t *texture);
void			move_up(t_map_texture *data);
void			move_down(t_map_texture *data);
void			move_left(t_map_texture *data);
void			move_right(t_map_texture *data);
void			ft_hook(mlx_key_data_t keydata, t_map_texture *data);
void			error(void);
void			free_map(char **str);
void			free_final(t_map_texture *content);
int				exit_game(t_map_texture *content);
int				get_map(char *av, t_map_texture *data);
int				check_ber(char *str);
int				check_arg(int ac, char *av);
char			**check_if_resolvable(char **copie, int x, int y);
char			**copy_content(t_map_texture *content, int line);
t_map_texture	*check_boxes_and_add(t_map_texture *content,
					int i, int j);
int				check_map(char **copie, int line, int col);
int				presence_of_characters(t_map_texture *content,
					int col, int line);
int				test_in_map(int line, int column, t_map_texture *content);
int				player_exit_collectible(t_map_texture *content);
int				check_boxes_valid(t_map_texture *content, int i, int j);
int				check_map(char **copie, int line, int col);
int				test_in_map(int line, int column, t_map_texture *content);
int				check_walls(t_map_texture *content);
int				check_size(t_map_texture *content);
#endif
