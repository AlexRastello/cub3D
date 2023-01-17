/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:16:49 by tandre            #+#    #+#             */
/*   Updated: 2023/01/10 10:03:00 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_vector	rotate_v(t_win *c, int d)
{
	t_vector	v;
	double		old_dirx;
	double		old_planex;

	old_dirx = c->dir.x;
	old_planex = c->plane.x;
	if (!d)
	{
		v.x = c->dir.x * cos(1.5708) - c->dir.y * sin(1.5708);
		v.y = old_dirx * sin(1.5708) + c->dir.y * cos(1.5708);
	}
	else
	{
		v.x = c->dir.x * cos(-1.5708) - c->dir.y * sin(-1.5708);
		v.y = old_dirx * sin(-1.5708) + c->dir.y * cos(-1.5708);
	}
	return (v);
}

void	init_vectors_helper(t_win	*cube, t_parse *parse)
{
	cube->dir.x = 0.0;
	cube->dir.y = 0.0;
	cube->plane.x = 0.0;
	cube->plane.y = 0.0;
	cube->pos.x = parse->spawnx + 0.5;
	cube->pos.y = parse->spawny + 0.5;
	cube->size_text = 200;
	cube->size_bg = 200;
	cube->size_pos = 10;
}

void	fill_img_helper(t_win *cube, int size_tmp)
{
	cube->img_empty = mlx_xpm_file_to_image(cube->mlx, \
		"textures/mini_map/empty.xpm", &cube->size_pos, &cube->size_pos);
	cube->img_pos = mlx_xpm_file_to_image(cube->mlx, \
		"textures/mini_map/pos.xpm", &cube->size_pos, &cube->size_pos);
	cube->img_wall = mlx_xpm_file_to_image(cube->mlx, \
		"textures/mini_map/wall.xpm", &size_tmp, &size_tmp);
	cube->img_out = mlx_xpm_file_to_image(cube->mlx, \
		"textures/mini_map/out.xpm", &size_tmp, &size_tmp);
	cube->walls = malloc(sizeof(t_data) * 4);
	cube->walls[0].img = mlx_xpm_file_to_image(cube->mlx, cube->parse->path_no, \
		&(cube->walls[0].width), &(cube->walls[0].height));
	cube->walls[1].img = mlx_xpm_file_to_image(cube->mlx, cube->parse->path_so, \
		&(cube->walls[1].width), &(cube->walls[1].height));
	cube->walls[2].img = mlx_xpm_file_to_image(cube->mlx, cube->parse->path_we, \
		&(cube->walls[2].width), &(cube->walls[2].height));
	cube->walls[3].img = mlx_xpm_file_to_image(cube->mlx, cube->parse->path_ea, \
		&(cube->walls[3].width), &(cube->walls[3].height));
}
