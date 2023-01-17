/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:13:02 by tandre            #+#    #+#             */
/*   Updated: 2023/01/09 00:40:19 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	empty_cell(char c)
{
	return (c == '0' || c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

unsigned int	get_data_color(int x, int y, void *addr, t_data img)
{
	char	*dst;

	dst = addr + (y * img.line_l + x * (img.bits_pixel / 8));
	return (*(unsigned int *)dst);
}

void	calc_dist(t_win *cube)
{
	if (cube->c.sdistx < cube->c.sdisty)
	{
		cube->c.sdistx += cube->c.deltadistx;
		cube->c.mapx += cube->c.stepx;
		cube->c.side = 0;
		if (cube->c.mapx > cube->pos.x)
			cube->c.texnum = 3;
		else
			cube->c.texnum = 2;
	}
	else
	{
		cube->c.sdisty += cube->c.deltadisty;
		cube->c.mapy += cube->c.stepy;
		cube->c.side = 1;
		if (cube->c.mapy > cube->pos.y)
			cube->c.texnum = 1;
		else
			cube->c.texnum = 0;
	}
}
