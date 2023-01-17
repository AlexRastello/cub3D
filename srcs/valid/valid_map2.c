/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:09:08 by arastell          #+#    #+#             */
/*   Updated: 2023/01/12 09:45:51 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	map_search_top(char **map, int i, int j)
{
	char	last_c;

	if (i >= 0 && (map[i][j] == '1' || map[i][j] == '0' || \
		is_start(map[i][j])))
		last_c = map[i][j];
	while (1)
	{
		if (i >= 0 && (map[i][j] == '1' || map[i][j] == '0' || \
			is_start(map[i][j])))
			last_c = map[i][j];
		if (i - 1 < 0 && last_c != '1')
			return (0);
		if (i >= 0 && (map[i][j] == ' ' && last_c != '1'))
			return (0);
		if ((i - 1 < 0 && last_c == '1') || (i == 0 && last_c == '1'))
			return (1);
		i--;
	}
	return (1);
}

static int	map_search_bottom(char **map, int i, int j)
{
	char	last_c;
	int		height;

	height = get_height(map);
	if (map[i] && (map[i][j] == '1' || map[i][j] == '0' || \
		is_start(map[i][j])))
		last_c = map[i][j];
	while (1)
	{
		if (map[i] && (map[i][j] == '1' || map[i][j] == '0' || \
			is_start(map[i][j])))
			last_c = map[i][j];
		if (!map[i + 1] && last_c != '1')
			return (0);
		if (i <= height && (map[i][j] == ' ' && last_c != '1'))
			return (0);
		if ((!map[i + 1] && last_c == '1') || (i == height && last_c == '1'))
			return (1);
		i++;
	}
	return (1);
}

static int	map_search_left(char **map, int i, int j)
{
	char	last_c;

	if (j >= 0 && (map[i][j] == '1' || map[i][j] == '0' || \
		is_start(map[i][j])))
		last_c = map[i][j];
	while (1)
	{
		if (j >= 0 && (map[i][j] == '1' || map[i][j] == '0' || \
			is_start(map[i][j])))
			last_c = map[i][j];
		if (j >= 0 && (map[i][j] == ' ' && last_c != '1'))
			return (0);
		if (j - 1 < 0 && last_c != '1')
			return (0);
		if ((j - 1 < 0 && last_c == '1') || (j == 0 && last_c == '1'))
			return (1);
		j--;
	}
	return (1);
}

static int	map_search_right(char **map, int i, int j)
{
	char	last_c;

	if (j < (int)ft_strlen(map[i]) && (map[i][j] == '1' || \
		map[i][j] == '0' || is_start(map[i][j])))
		last_c = map[i][j];
	while (1)
	{
		if (j < (int)ft_strlen(map[i]) && (map[i][j] == '1' || \
			map[i][j] == '0' || is_start(map[i][j])))
			last_c = map[i][j];
		if (j + 1 > (int)ft_strlen(map[i]) && last_c != '1')
			return (0);
		if (j < (int)ft_strlen(map[i]) && (map[i][j] == ' ' && last_c != '1'))
			return (0);
		if ((j + 1 > (int)ft_strlen(map[i]) && last_c == '1') || \
			(j == (int)ft_strlen(map[i]) && last_c == '1'))
			return (1);
		j++;
	}
	return (1);
}

int	map_is_close(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_start(map[i][j]))
			{
				if (!map_search_top(map, i, j) || \
					!map_search_bottom(map, i, j) || \
					!map_search_left(map, i, j) || \
					!map_search_right(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
