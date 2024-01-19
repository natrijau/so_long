/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:35:15 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/15 17:54:15 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_MAP_H
# define PARSING_MAP_H

# include "./main.h"

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