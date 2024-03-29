/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:32:29 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/25 13:54:21 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	move_up(t_map_texture *data)
{
	if (data->map[data->x][data->y] == 'C')
	{
		data->compte_collectible++;
		put_texture(data->mlx, "./herbe.png", (data->x) * 64, (data->y) * 64);
		data->player = put_texture(data->mlx, "./remus.png",
				(data->x) * 64, (data->y) * 64);
		data->map[data->x][data->y] = '0';
	}
	if (data->map[data->x][data->y] == 'E'
			&& (data->collectible == data->compte_collectible))
	{
		ft_putstr_fd("\n\tCongratulations, you're finished!!!\n", 1);
		mlx_close_window(data->mlx);
	}
	ft_printf("number of steps:%d\n", data->moves);
	data->moves ++;
	data->x -= 1;
	data->player->instances[0].y -= 64;
}

//Move down
void	move_down(t_map_texture *data)
{
	if (data->map[data->x][data->y] == 'C')
	{
		data->compte_collectible++;
		put_texture(data->mlx, "./herbe.png", (data->x) * 64, (data->y) * 64);
		data->player = put_texture(data->mlx, "./remus.png",
				(data->x) * 64, (data->y) * 64);
		data->map[data->x][data->y] = '0';
	}
	if (data->map[data->x][data->y] == 'E'
			&& (data->collectible == data->compte_collectible))
	{
		ft_putstr_fd("\n\tCongratulations, you're finished!!!\n", 1);
		mlx_close_window(data->mlx);
	}
	ft_printf("number of steps:%d\n", data->moves);
	data->x += 1;
	data->moves ++;
	data->player->instances[0].y += 64;
}

//Move move_left
void	move_left(t_map_texture *data)
{
	if (data->map[data->x][data->y] == 'C')
	{
		data->compte_collectible++;
		put_texture(data->mlx, "./herbe.png", (data->x) * 64, (data->y) * 64);
		data->player = put_texture(data->mlx, "./remus.png",
				(data->x) * 64, (data->y) * 64);
		data->map[data->x][data->y] = '0';
	}
	if (data->map[data->x][data->y] == 'E'
			&& (data->collectible == data->compte_collectible))
	{
		ft_putstr_fd("\n\tCongratulations, you're finished!!!\n", 1);
		mlx_close_window(data->mlx);
	}
	ft_printf("number of steps:%d\n", data->moves);
	data->y -= 1;
	data->moves ++;
	data->player->instances[0].x -= 64;
}

//Move right
void	move_right(t_map_texture *data)
{
	if (data->map[data->x][data->y] == 'C')
	{
		data->compte_collectible++;
		put_texture(data->mlx, "./herbe.png", (data->x) * 64, (data->y) * 64);
		data->player = put_texture(data->mlx, "./remus.png",
				(data->x) * 64, (data->y) * 64);
		data->map[data->x][data->y] = '0';
	}
	if (data->map[data->x][data->y] == 'E'
			&& (data->collectible == data->compte_collectible))
	{
		ft_putstr_fd("\n\tCongratulations, you're finished!!!\n", 1);
		mlx_close_window(data->mlx);
	}
	ft_printf("number of steps:%d\n", data->moves);
	data->y += 1;
	data->moves ++;
	data->player->instances[0].x += 64;
}

//Loop for move or close window
void	ft_hook(mlx_key_data_t keydata, t_map_texture *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if ((mlx_is_key_down(data->mlx, MLX_KEY_W)
			&& data->map[data->x - 1][data->y] != '1'))
		move_up(data);
	else if ((mlx_is_key_down(data->mlx, MLX_KEY_S)
			&& data->map[data->x + 1][data->y] != '1'))
		move_down(data);
	else if ((mlx_is_key_down(data->mlx, MLX_KEY_A)
			&& data->map[data->x][data->y - 1] != '1'))
		move_left(data);
	else if ((mlx_is_key_down(data->mlx, MLX_KEY_D)
			&& data->map[data->x][data->y + 1] != '1'))
		move_right(data);
	else if (data->map[data->x][data->y] == 'E'
			&& (data->collectible == data->compte_collectible))
	{
		ft_putstr_fd("\n\tCongratulations, you're finished!!!\n", 1);
		mlx_close_window(data->mlx);
	}
}
