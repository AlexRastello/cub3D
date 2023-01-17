/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:09:05 by arastell          #+#    #+#             */
/*   Updated: 2023/01/05 10:18:16 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

int	is_start(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

static void	map_format_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (is_empty(map[i]))
			error_valid(map, NULL, "Empty line on description map");
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' && \
				map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' && \
				map[i][j] != ' ')
				error_valid(map, NULL, "Invalid character present in map");
			j++;
		}
		i++;
	}
}

static int	map_contain_start(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

void	is_good_map(char *file)
{
	char	**map;
	int		i;

	i = 0;
	map = get_map(file);
	if (!map)
		error_valid(NULL, NULL, "0 map contain in file");
	if (!map_contain_start(map))
		error_valid(map, NULL, "Map start error");
	map_format_valid(map);
	if (!map_is_close(map))
		error_valid(map, NULL, "Map is not close");
	free_split(map);
}
