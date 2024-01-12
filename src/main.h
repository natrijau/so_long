/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:35:25 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/12 17:48:19 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_texture
{
	mlx_image_t	*img;
	mlx_image_t	*laine;
	mlx_image_t	*collectible;
	mlx_image_t	*murs;
	mlx_image_t	*sol;
	mlx_image_t	*exit;
	int			x;
	int			y;
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
	int				x;
	int				y;
	int				collectible;
	int				compte_collectible;
	int				moves;
	int				width;
	int				height;
}	t_map_texture;

mlx_image_t		*put_texture(mlx_t *mlx, char *path, int x, int y);
t_map_texture	*images_in_map(t_map_texture *content, int x, int y);
mlx_image_t		*put_texture(mlx_t *mlx, char *path, int x, int y);
void			load_file(void);
void			display_image(t_map_texture *content);
void			move_up(t_map_texture *data);
void			move_down(t_map_texture *data);
void			move_left(t_map_texture *data);
void			move_right(t_map_texture *data);
void			ft_hook(mlx_key_data_t keydata, t_map_texture *data);
void			error(void);

#endif
