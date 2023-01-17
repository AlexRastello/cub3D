/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:26:03 by tandre            #+#    #+#             */
/*   Updated: 2023/01/10 09:59:36 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_parse
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		color_f;
	int		color_c;
	double	spawnx;
	double	spawny;
	char	start;
	char	**map;
}	t_parse;

typedef struct s_vector
{
	double	x;
	double	y;

}	t_vector;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		*addr_txt;
	int		bits_pixel;
	int		line_l;
	int		width;
	int		height;
	int		endian;
}		t_data;

typedef struct s_ray_calc
{
	t_vector	raydir;
	int			mapx;
	int			mapy;
	double		camerax;
	double		sdistx;
	double		sdisty;
	double		deltadistx;
	double		deltadisty;
	double		stepx;
	double		stepy;
	int			hit;
	int			side;
	double		walldist;
	int			texnum;
	int			lineheight;
	int			dstart;
	int			dend;
	double		wallx;
	int			texx;
	double		step;
	double		texpos;

}	t_ray_calc;

typedef struct s_win
{
	t_data		data;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_parse		*parse;
	t_data		*walls;
	t_ray_calc	c;
	int			size_text;
	int			size_bg;
	int			size_pos;
	void		*img_bg;
	void		*img_empty;
	void		*img_pos;
	void		*img_wall;
	void		*img_out;
	void		*mlx;
	void		*mlx_win;
}	t_win;

typedef struct s_map_calc
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	c_i;
	int	c_j;

}	t_map_calc;

#endif