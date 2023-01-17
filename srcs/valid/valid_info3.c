/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:09:03 by arastell          #+#    #+#             */
/*   Updated: 2023/01/05 07:09:04 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	is_only_color_2(char **strs)
{
	int	j;

	j = 0;
	if (!ft_isdigit(strs[1][0]))
		return (0);
	while (strs[1][j])
	{
		if (strs[1][j + 1] && !ft_isdigit(strs[1][j]) && \
		!ft_isdigit(strs[1][j + 1]))
			return (0);
		j++;
	}
	if (strs[1][j - 1] && !ft_isdigit(strs[1][j - 1]))
		return (0);
	return (1);
}

static int	is_only_color_4(char **strs)
{
	int	i;
	int	j;

	i = 1;
	while (strs[i])
	{
		j = 0;
		if (!ft_isdigit(strs[i][0]))
			return (0);
		while (strs[i][j])
		{
			if (strs[i][j + 1] && !ft_isdigit(strs[i][j]) && \
			!ft_isdigit(strs[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	if (!ft_isdigit(strs[i - 1][j - 1]))
		return (0);
	return (1);
}

int	is_only_color(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i == 2)
	{
		if (!is_only_color_2(strs))
			return (0);
	}
	if (i == 4)
	{
		if (!is_only_color_4(strs))
			return (0);
	}
	return (1);
}
