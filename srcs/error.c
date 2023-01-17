/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:57:32 by arastell          #+#    #+#             */
/*   Updated: 2023/01/10 12:54:39 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	error_valid(char **s1, char **s2, char *msg)
{
	printf("Error\n%s\n", msg);
	if (s1)
		free_split(s1);
	if (s2)
		free_split(s2);
	exit(1);
}

void	error_cube(t_win *cube, char *msg)
{
	printf("Error\n%s\n", msg);
	free_parsing(cube->parse);
	exit(1);
}
