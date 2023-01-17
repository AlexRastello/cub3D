/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:10:07 by arastell          #+#    #+#             */
/*   Updated: 2023/01/10 12:54:15 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_parsing(t_parse *parse)
{
	free_split(parse->map);
	free(parse->path_no);
	free(parse->path_so);
	free(parse->path_we);
	free(parse->path_ea);
}

void	free_cube(t_win *cube)
{
	free_parsing(cube->parse);
	free(cube->parse);
	free(cube);
}
