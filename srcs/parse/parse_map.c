/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:08:52 by arastell          #+#    #+#             */
/*   Updated: 2023/01/12 09:44:15 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static char	*resize_line(char *line, size_t max_size)
{
	size_t	current_size;
	char	*tmp;

	current_size = ft_strlen(line);
	tmp = malloc(sizeof(char) * (ft_strlen(line) + \
		(max_size - current_size) + 1));
	ft_strlcpy(tmp, line, ft_strlen(line) + 1);
	while (current_size < max_size)
	{
		tmp[current_size] = ' ';
		current_size++;
	}
	tmp[current_size] = '\0';
	free(line);
	return (tmp);
}

void	format_map(char **map)
{
	int		i;
	size_t	max_size;

	i = 0;
	max_size = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > max_size)
			max_size = ft_strlen(map[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < max_size)
			map[i] = resize_line(map[i], max_size);
		i++;
	}
}

static void	get_map_utils(char **content, char *line, int i)
{
	if (i > 0 && is_infos(line))
	{
		content[i] = 0;
		error_valid(content, NULL, "Invalid declaration map");
	}
}

char	**get_map(char *file)
{
	int		fd;
	int		i;
	char	**content;
	char	*line;

	i = 0;
	content = malloc(sizeof(char *) * (get_count_gnl(file) + 1));
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		get_map_utils(content, line, i);
		if (i > 0 || (!is_infos(line) && !is_empty(line)))
			content[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	close(fd);
	if (i == 0)
		return (0);
	content[i] = 0;
	format_map(content);
	return (content);
}
