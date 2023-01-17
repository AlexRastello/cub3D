/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:29:04 by tandre            #+#    #+#             */
/*   Updated: 2023/01/13 08:45:53 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_ray_calc	get_calculs_2(t_win *cube, int i)
{
	t_ray_calc	c;

	c.mapx = cube->pos.x;
	c.mapy = cube->pos.y;
	c.camerax = 2 * i / (double)SCREENWIDTH - 1;
	c.raydir.x = cube->dir.x + cube->plane.x * c.camerax;
	c.raydir.y = cube->dir.y + cube->plane.y * c.camerax;
	if (!c.raydir.x)
		c.deltadistx = 400000;
	else
		c.deltadistx = fabs(1 / c.raydir.x);
	if (!c.raydir.y)
		c.deltadisty = 400000;
	else
		c.deltadisty = fabs(1 / c.raydir.y);
	return (c);
}

t_ray_calc	get_calculs(t_win *cube, int i)
{
	t_ray_calc	c;

	c = get_calculs_2(cube, i);
	c.stepx = -1;
	c.stepy = -1;
	if (c.raydir.x < 0)
		c.sdistx = (cube->pos.x - c.mapx) * c.deltadistx;
	else
	{
		c.stepx = 1;
		c.sdistx = (c.mapx + 1.0 - cube->pos.x) * c.deltadistx;
	}
	if (c.raydir.y < 0)
		c.sdisty = (cube->pos.y - c.mapy) * c.deltadisty;
	else
	{
		c.stepy = 1;
		c.sdisty = (c.mapy + 1.0 - cube->pos.y) * c.deltadisty;
	}
	return (c);
}

void	calc_dist2(t_win	*cube)
{
	cube->c.hit = 1;
	if (!cube->c.side)
		cube->c.walldist = (cube->c.sdistx - cube->c.deltadistx);
	else
		cube->c.walldist = (cube->c.sdisty - cube->c.deltadisty);
	cube->c.lineheight = (int)(SCREENHEIGHT / cube->c.walldist);
	cube->c.dstart = -cube->c.lineheight / 2 + SCREENHEIGHT / 2;
	cube->c.dend = cube->c.lineheight / 2 + SCREENHEIGHT / 2;
	if (cube->c.dstart < 0)
		cube->c.dstart = 0;
	if (cube->c.dend >= SCREENHEIGHT)
		cube->c.dend = SCREENHEIGHT - 1;
	if (!cube->c.side)
		cube->c.wallx = cube->pos.y + cube->c.walldist * cube->c.raydir.y;
	else
		cube->c.wallx = cube->pos.x + cube->c.walldist * cube->c.raydir.x;
	cube->c.wallx -= floor((cube->c.wallx));
	cube->c.texx = (int)(cube->c.wallx * (double)TEXWIDTH);
	if ((!cube->c.side && cube->c.raydir.x > 0)
		|| (cube->c.side == 1 && cube->c.raydir.y < 0))
		cube->c.texx = TEXWIDTH - cube->c.texx - 1;
	cube->c.step = 1.0 * TEXHEIGHT / cube->c.lineheight;
	cube->c.texpos = (cube->c.dstart - SCREENHEIGHT / 2
			+ cube->c.lineheight / 2) * cube->c.step;
}

void	dda_draw(t_win	*cube, int i)
{
	int	y;
	int	texy;
	int	color;

	calc_dist(cube);
	if (empty_cell(cube->parse->map[cube->c.mapy][cube->c.mapx]))
		return ;
	calc_dist2(cube);
	y = cube->c.dstart;
	while (++y <= cube->c.dend)
	{
		texy = (int)cube->c.texpos & (TEXHEIGHT - 1);
		cube->c.texpos += cube->c.step;
		color = get_data_color(cube->c.texx, texy, \
			cube->walls[cube->c.texnum].addr_txt, cube->walls[cube->c.texnum]);
		pixel_put_color(cube, i, y, color);
	}
}

void	render(t_win *cube)
{
	int	i;

	draw_floor_ceiling(*cube);
	i = -1;
	while (++i < (double) SCREENWIDTH)
	{
		cube->c = get_calculs(cube, i);
		cube->c.hit = 0;
		while (cube->c.hit == 0)
		{
			dda_draw(cube, i);
		}
	}
}
