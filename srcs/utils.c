/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:10:16 by arastell          #+#    #+#             */
/*   Updated: 2023/01/09 02:17:42 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_cmp(char *s1, char *s2)
{
	if (!ft_strcmp(s1, s2))
		return (1);
	return (0);
}

int	get_count_gnl(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int	notify(int e, void *p)
{
	(void) e;
	(void) p;
	exit(0);
}

void	left_right(t_win *c, int key)
{
	t_vector	v;

	if (key == 0)
		v = rotate_v(c, 1);
	else
		v = rotate_v(c, 0);
	if (empty_cell(c->parse->map[(int)(c->pos.y + v.y * 0.28)] \
		[(int)(c->pos.x + v.x * 0.28)]))
	{
		c->pos.x += v.x * 0.25;
		c->pos.y += v.y * 0.25;
	}
}

void	moove(t_win	*c, int key)
{
	if (key == 13)
	{
		if (empty_cell(c->parse->map[(int)c->pos.y][(int) \
			(c->pos.x + c->dir.x * 0.38)]))
			c->pos.x += c->dir.x * 0.35;
		if (empty_cell(c->parse->map[(int)(c->pos.y + c->dir.y * 0.38)] \
			[(int)c->pos.x]))
			c->pos.y += c->dir.y * 0.35;
	}
	else if (key == 1)
	{
		if (empty_cell(c->parse->map[(int)c->pos.y] \
			[(int)(c->pos.x - c->dir.x * 0.38)]))
			c->pos.x -= c->dir.x * 0.35;
		if (empty_cell(c->parse->map[(int)(c->pos.y - c->dir.y * 0.38)] \
			[(int)c->pos.x]))
			c->pos.y -= c->dir.y * 0.35;
	}
	else if (key == 2 || key == 0)
		left_right(c, key);
}
