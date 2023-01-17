/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:57:24 by tandre            #+#    #+#             */
/*   Updated: 2023/01/09 00:57:47 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "cub3D.h"

void			init_textures(t_win	*cube);
void			pixel_put(t_win cube, int x, int y, int side);
void			pixel_put_color(t_win *cube, int x, int y, int color);
void			draw_floor_ceiling(t_win cube);
void			display_mini_map(t_win *cube);
void			render(t_win *cube);
unsigned int	get_data_color(int x, int y, void *addr, t_data img);
int				empty_cell(char c);
void			calc_dist(t_win *cube);

#endif