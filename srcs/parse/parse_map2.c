/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:08:35 by arastell          #+#    #+#             */
/*   Updated: 2023/01/05 07:09:56 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	update_map2(char *line, int j, char **tmp)
{
	size_t	k;

	while (j < 10)
	{
		tmp[j] = malloc(sizeof(char) * (ft_strlen(line) + 21));
		k = 0;
		while (k < (ft_strlen(line) + 20))
		{
			tmp[j][k] = '2';
			k++;
		}
		tmp[j][k] = '\0';
		j++;
	}
	return (j);
}

void	update_map3(int j, char **tmp, char **map)
{
	size_t	k;

	while (j < (get_height(map) + 20))
	{
		tmp[j] = malloc(sizeof(char) * (ft_strlen(map[0]) + 21));
		k = 0;
		while (k < ft_strlen(map[0]) + 20)
		{
			tmp[j][k] = '2';
			k++;
		}
		tmp[j][k] = '\0';
		j++;
	}
	tmp[j] = 0;
}

char	**update_map(char **map)
{
	size_t	i;
	int		j;
	char	**tmp;

	j = 0;
	i = 0;
	tmp = malloc(sizeof(char *) * (get_height(map) + 21));
	j = update_map2(map[0], j, tmp);
	while (map[i])
	{
		tmp[j] = malloc(sizeof(char) * (ft_strlen(map[0]) + 21));
		ft_strcpy(tmp[j], "2222222222");
		ft_strcat(tmp[j], map[i]);
		ft_strcat(tmp[j], "2222222222");
		j++;
		i++;
	}
	update_map3(j, tmp, map);
	free_split(map);
	return (tmp);
}
