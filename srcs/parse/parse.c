/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:08:43 by arastell          #+#    #+#             */
/*   Updated: 2023/01/09 00:28:22 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	fill_pos(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (is_start(parse->map[i][j]))
			{
				parse->spawny = (double)i;
				parse->spawnx = (double)j;
				parse->start = parse->map[i][j];
			}
			j++;
		}
		i++;
	}
}

void	replace_blank_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '2';
			j++;
		}
		i++;
	}
}

t_parse	*parsing(char	*file)
{
	t_parse	*parse;
	int		i;

	i = 0;
	parse = malloc(sizeof(t_parse));
	parse->map = get_map(file);
	if (get_height(parse->map) == 0)
	{
		free(parse);
		error_valid(NULL, NULL, "0 map present in file");
	}
	parse->map = update_map(parse->map);
	replace_blank_map(parse->map);
	fill_infos(file, parse);
	fill_pos(parse);
	return (parse);
	return (NULL);
}
