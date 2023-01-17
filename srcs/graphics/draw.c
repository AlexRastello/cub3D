/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:04:31 by tandre            #+#    #+#             */
/*   Updated: 2023/01/12 09:27:51 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"
#include <math.h>
#include "mlx.h"

void	pixel_put(t_win cube, int x, int y, int side)
{
	char	*dst;
	int		color;
	t_data	*data;

	data = &cube.data;
	color = 0;
	if (side == -1)
		color = cube.parse->color_c;
	else if (side == -2)
		color = cube.parse->color_f;
	if (x >= SCREENWIDTH | x < 0 | y >= SCREENHEIGHT | y <= 0)
		return ;
	dst = data->addr + (y * data->line_l + x * (data->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pixel_put_color(t_win *cube, int x, int y, int color)
{
	t_data	*data;
	char	*dst;

	data = &cube->data;
	if (x >= SCREENWIDTH | x < 0 | y >= SCREENHEIGHT | y <= 0)
		return ;
	dst = data->addr + (y * data->line_l + x * (data->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_ceiling(t_win cube)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SCREENHEIGHT / 2)
	{
		x = -1;
		while (++x < SCREENWIDTH)
			pixel_put(cube, x, y, -1);
	}
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		while (++x < SCREENWIDTH)
			pixel_put(cube, x, y, -2);
	}
}
