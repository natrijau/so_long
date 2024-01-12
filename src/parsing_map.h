/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:35:15 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/12 17:52:38 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_MAP_H
# define PARSING_MAP_H

# include "./main.h"

t_map_texture	*copie_content(t_map_texture *copie,
					t_map_texture *content, int line);
int				check_map(t_map_texture *content, int line, int col);
t_map_texture	*check_if_resolvable(t_map_texture *copie,
					int x, int y);
int				test_in_map(int line, int column, t_map_texture *content);
int				check_walls(t_map_texture *content);
int				check_size(t_map_texture *content);
#endif