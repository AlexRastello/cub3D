/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:09:01 by arastell          #+#    #+#             */
/*   Updated: 2023/01/05 07:09:02 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_contain_double(char *str, int arr[6])
{
	if (is_cmp(str, "NO") && arr[0] == 1)
		return (1);
	if (is_cmp(str, "SO") && arr[1] == 1)
		return (1);
	if (is_cmp(str, "WE") && arr[2] == 1)
		return (1);
	if (is_cmp(str, "EA") && arr[3] == 1)
		return (1);
	if (is_cmp(str, "F") && arr[4] == 1)
		return (1);
	if (is_cmp(str, "C") && arr[5] == 1)
		return (1);
	return (0);
}

static int	is_good_texture(char *line)
{
	int	fd;

	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

void	valid_texture(char **content, char **strs, int arr[6])
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		error_valid(content, strs, "Not a valid format texture");
	if (is_contain_double(strs[0], arr))
		error_valid(content, strs, "Double texture present in file");
	if (is_cmp(strs[0], "NO"))
		arr[0] = 1;
	if (is_cmp(strs[0], "SO"))
		arr[1] = 1;
	if (is_cmp(strs[0], "WE"))
		arr[2] = 1;
	if (is_cmp(strs[0], "EA"))
		arr[3] = 1;
	if (!is_cmp(strs[0], "NO") && !is_cmp(strs[0], "SO") && \
		!is_cmp(strs[0], "WE") && !is_cmp(strs[0], "EA"))
		error_valid(content, strs, "Id texture is not good");
	if (!is_good_texture(strs[1]))
		error_valid(content, strs, "Not a good path for texture");
}
