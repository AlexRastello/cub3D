/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:08:49 by arastell          #+#    #+#             */
/*   Updated: 2023/01/09 00:28:57 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	fill_color_4(char **strs, t_parse *parse)
{
	char	*tr1;
	char	*tr2;

	tr1 = ft_strtrim(strs[1], ",");
	tr2 = ft_strtrim(strs[2], ",");
	if (is_cmp(strs[0], "F"))
		parse->color_f = create_color(tr1, tr2, strs[3]);
	if (is_cmp(strs[0], "C"))
		parse->color_c = create_color(tr1, tr2, strs[3]);
	free(tr1);
	free(tr2);
}

void	fill_color(char **strs, t_parse *parse)
{
	char	**color;
	int		i;

	i = 0;
	while (strs[i])
		i++;
	if (i == 2)
	{
		color = ft_split(strs[1], ',');
		if (is_cmp(strs[0], "F"))
			parse->color_f = create_color(color[0], color[1], color[2]);
		if (is_cmp(strs[0], "C"))
			parse->color_c = create_color(color[0], color[1], color[2]);
		free_split(color);
	}
	if (i == 4)
		fill_color_4(strs, parse);
}

void	fill_infos(char *file, t_parse *parse)
{
	char	**infos;
	char	**strs;
	int		i;

	infos = get_infos(file);
	i = 0;
	while (infos[i])
	{
		strs = ft_split(infos[i], ' ');
		if (is_cmp(strs[0], "NO"))
			parse->path_no = ft_strdup(strs[1]);
		if (is_cmp(strs[0], "SO"))
			parse->path_so = ft_strdup(strs[1]);
		if (is_cmp(strs[0], "WE"))
			parse->path_we = ft_strdup(strs[1]);
		if (is_cmp(strs[0], "EA"))
			parse->path_ea = ft_strdup(strs[1]);
		if (is_cmp(strs[0], "F") || is_cmp(strs[0], "C"))
			fill_color(strs, parse);
		free_split(strs);
		i++;
	}
	free_split(infos);
}

char	**get_infos(char *file)
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
		if (!line || (is_map(line) && !is_empty(line)))
		{
			if (line)
				free(line);
			break ;
		}
		if (!is_empty(line))
			content[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	close(fd);
	content[i] = 0;
	return (content);
}
