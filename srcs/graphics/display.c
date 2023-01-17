/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:42:51 by tandre            #+#    #+#             */
/*   Updated: 2023/01/10 10:09:54 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	display_mini_map_helper(t_win *cube, t_map_calc c)
{
	(void) cube;
	(void) c;
	if (cube->parse->map[c.i][c.j] == '0' || \
		is_start(cube->parse->map[c.i][c.j]))
		mlx_put_image_to_window(cube->mlx, cube->mlx_win, \
			cube->img_empty, c.c_j * 10, c.c_i * 10);
	if (cube->parse->map[c.i][c.j] == '1')
		mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img_wall,
			c.c_j * 10, c.c_i * 10);
	if (cube->parse->map[c.i][c.j] == '2')
		mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img_out,
			c.c_j * 10, c.c_i * 10);
}

void	display_mini_map(t_win *cube)
{
	t_map_calc	c;

	c.x = (int)cube->pos.x;
	c.y = (int)cube->pos.y;
	c.i = c.y - 10;
	c.c_i = 0;
	while (c.i < c.y + 10 && c.i <= get_height(cube->parse->map))
	{
		c.c_j = 0;
		c.j = c.x - 10;
		while (c.j < c.x + 10 && c.j < (int)ft_strlen(cube->parse->map[c.i]))
		{
			display_mini_map_helper(cube, c);
			c.c_j++;
			c.j++;
		}
		c.c_i++;
		c.i++;
	}
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img_pos, \
		(cube->size_bg / 2), (cube->size_bg / 2));
}
