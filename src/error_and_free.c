/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:32:34 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/24 14:08:44 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	free_final(t_map_texture *content)
{
	free(content->get_map);
	free_map(content->map);
	mlx_terminate(content->mlx);
	free(content);
}

void	free_map(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
