/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:32:13 by tandre            #+#    #+#             */
/*   Updated: 2023/01/12 09:29:21 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

void	rotate(t_win *c, int d)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = c->dir.x;
	old_planex = c->plane.x;
	if (!d)
	{
		c->dir.x = c->dir.x * cos(0.092) - c->dir.y * sin(0.092);
		c->dir.y = old_dirx * sin(0.092) + c->dir.y * cos(0.092);
		c->plane.x = c->plane.x * cos(0.092) - c->plane.y * sin(0.092);
		c->plane.y = old_planex * sin(0.092) + c->plane.y * cos(0.092);
	}
	else
	{
		c->dir.x = c->dir.x * cos(-0.092) - c->dir.y * sin(-0.092);
		c->dir.y = old_dirx * sin(-0.092) + c->dir.y * cos(-0.092);
		c->plane.x = c->plane.x * cos(-0.092) - \
			c->plane.y * sin(-0.092);
		c->plane.y = old_planex * sin(-0.092) + \
			c->plane.y * cos(-0.092);
	}
}

int	key_hook(int key, t_win *cube)
{
	if (key == 53)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_win);
		free_parsing(cube->parse);
		exit(0);
	}
	if (key == 0 || key == 1 || key == 2 || key == 13)
		moove(cube, key);
	if (key == 123)
		rotate(cube, 1);
	if (key == 124)
		rotate(cube, 0);
	mlx_destroy_image(cube->mlx, cube->data.img);
	cube->data.img = mlx_new_image(cube->mlx, SCREENWIDTH, SCREENHEIGHT);
	cube->data.addr = mlx_get_data_addr(cube->data.img, \
		&cube->data.bits_pixel, &cube->data.line_l, &cube->data.endian);
	render(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->data.img, 0, 0);
	display_mini_map(cube);
	return (0);
}

void	init_vectors(t_win	*cube, t_parse *parse)
{
	init_vectors_helper(cube, parse);
	if (parse->start == 'N')
	{
		cube->dir.y = -1.0;
		cube->plane.x = 0.7;
	}
	else if (parse->start == 'S')
	{
		cube->dir.y = 1.0;
		cube->plane.x = 0.7;
	}
	else if (parse->start == 'E')
	{
		cube->dir.x = 1.0;
		cube->plane.y = 0.7;
	}
	else
	{
		cube->dir.x = -1.0;
		cube->plane.y = 0.7;
	}
}

void	fill_img(t_win *cube)
{
	int		size_tmp;

	size_tmp = 100;
	fill_img_helper(cube, size_tmp);
}

int	main(int argc, char **argv)
{
	t_win		*cube;

	valid(argc, argv);
	cube = malloc(sizeof(t_win) * 1);
	cube->parse = parsing(argv[1]);
	cube->mlx = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx, SCREENWIDTH, \
		SCREENHEIGHT, "CUBESQUE");
	init_vectors(cube, cube->parse);
	fill_img(cube);
	valid_img(cube);
	cube->data.img = mlx_new_image(cube->mlx, SCREENWIDTH, \
		SCREENHEIGHT);
	cube->data.addr = mlx_get_data_addr(cube->data.img, &cube->data.bits_pixel,
			&cube->data.line_l, &cube->data.endian);
	render(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->data.img, 0, 0);
	display_mini_map(cube);
	mlx_hook(cube->mlx_win, 2, (1L << 0), key_hook, cube);
	mlx_hook(cube->mlx_win, 17, 0, notify, NULL);
	mlx_loop(cube->mlx);
	return (0);
}
