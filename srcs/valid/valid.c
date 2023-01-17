/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:09:15 by arastell          #+#    #+#             */
/*   Updated: 2023/01/10 10:10:56 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	is_good_file(char *file)
{
	char	**path;
	int		contain;
	int		i;

	i = 0;
	contain = 0;
	path = ft_split(file, '.');
	while (path[i])
	{
		if (!ft_strcmp(path[i], "cub") && i > 0)
			contain = 1;
		i++;
	}
	free_split(path);
	if (!contain)
	{
		printf("Error\nnot a valid extension for map\n");
		return (0);
	}
	if (open(file, O_RDONLY) < 0)
	{
		perror("Error\nOpen");
		return (0);
	}
	return (1);
}

void	valid_img(t_win *cube)
{
	int		i;

	i = -1;
	if (!cube->img_pos || !cube->img_wall || !cube->img_out || \
		!cube->img_empty || !cube->walls[0].img || !cube->walls[1].img || \
		!cube->walls[2].img || !cube->walls[3].img)
		error_cube(cube, "Not a good file xpm");
	while (++i < 4)
		cube->walls[i].addr_txt = (int *)mlx_get_data_addr(cube->walls[i].img, \
		&cube->walls[i].bits_pixel, &cube->walls[i].line_l, \
		&cube->walls[i].endian);
}

void	valid(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nnb of args invalid", 2);
		exit(1);
	}
	if (!is_good_file(argv[1]))
		exit(1);
	if (!is_good_infos(argv[1]))
		exit(1);
	is_good_map(argv[1]);
}
