/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:09:12 by arastell          #+#    #+#             */
/*   Updated: 2023/01/05 08:57:45 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	fill_valid_arr(int arr[6])
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;
	arr[5] = 0;
}

int	check_valid_arr(int arr[6])
{
	if (!arr[0] || !arr[1] || !arr[2] || !arr[3])
	{
		printf("Error\nMissing a texture\n");
		return (0);
	}
	if (!arr[4] || !arr[5])
	{
		printf("Error\nMissing a color\n");
		return (0);
	}
	return (1);
}

int	is_infos(char *line)
{
	int		i;
	char	**strs;

	i = 0;
	strs = ft_split(line, ' ');
	if (is_cmp(strs[0], "F") || is_cmp(strs[0], "C") || \
		is_cmp(strs[0], "NO") || is_cmp(strs[0], "SO") || \
		is_cmp(strs[0], "WE") || is_cmp(strs[0], "EA"))
	{
		free_split(strs);
		return (1);
	}
	free_split(strs);
	return (0);
}
