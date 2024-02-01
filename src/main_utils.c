/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:34:24 by natrijau          #+#    #+#             */
/*   Updated: 2024/01/25 13:42:53 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

int	check_double_n(t_map_texture *content)
{
	int		i;
	char	*str;

	str = content->get_map->str;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_putstr_fd(
				"The map must not be separated by a newline", 2);
			free(content->get_map->str);
			free(content->get_map);
			free(content);
			return (1);
		}
		i++;
	}
	return (0);
}

t_map_texture	*init_map(t_map_texture *content)
{
	while (content->get_map->tmp)
	{
		content->get_map->str = ft_strjoin(content->get_map->str,
				content->get_map->tmp);
		if (content->get_map->str == NULL)
		{
			free(content);
			exit(EXIT_FAILURE);
		}
		free(content->get_map->tmp);
		content->get_map->tmp = get_next_line(content->get_map->byte);
	}
	if (check_double_n(content) == 1)
		return (NULL);
	content->map = ft_split(content->get_map->str, '\n');
	free(content->get_map->str);
	if (content->map == NULL)
	{
		free_map(content->map);
		exit(EXIT_FAILURE);
	}
	close(content->get_map->byte);
	return (content);
}

//Get map
int	get_map(char *av, t_map_texture *data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	data->get_map = map;
	map->byte = open(av, O_RDWR);
	if (map->byte == -1)
		return (-1);
	map->str = get_next_line(map->byte);
	if (map->str == NULL)
	{
		free(map->str);
		close(map->byte);
		return (1);
	}
	map->tmp = get_next_line(map->byte);
	return (0);
}

//Check format
int	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (((str[i - 1] == 'r') && (str[i - 2] == 'e'))
		&& ((str[i - 3] == 'b') && (str[i - 4] == '.')))
		return (0);
	else
	{
		ft_putstr_fd("The format of the map is not good!\n", 2);
		return (1);
	}
}

//Check numb of arg and ber
int	check_arg(int ac, char *av)
{
	if (ac != 2)
	{
		ft_putstr_fd("The number of arguments is invalid!\n", 2);
		return (1);
	}
	else if (check_ber(av) == 1)
		return (1);
	return (0);
}
