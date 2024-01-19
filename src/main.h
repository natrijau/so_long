/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:35:25 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/19 16:59:04 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

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

//a modifier en game_t
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
t_map_texture	*images_in_map(t_map_texture *content, int x, int y);
t_map_texture	*init_map(t_map_texture *content);
mlx_image_t		*put_texture(mlx_t *mlx, char *path, int x, int y);
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
// void			free_map2(t_map_texture *data);
int				exit_game(t_map_texture *content);
int				get_map(char *av, t_map_texture *data);
int				check_ber(char *str);
int				check_arg(int ac, char *av);

#endif
