/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:25:38 by tandre            #+#    #+#             */
/*   Updated: 2023/01/09 00:25:39 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

# include "cub3D.h"

int		check_valid_arr(int arr[6]);
int		is_good_infos(char *file);
int		map_is_close(char **map);
int		get_height(char **map);
int		is_start(char c);
int		is_contain_double(char *str, int arr[6]);
int		is_only_color(char **strs);
void	is_good_map(char *file);
void	fill_valid_arr(int arr[6]);
void	valid(int argc, char **argv);
void	valid_img(t_win *cube);
void	valid_texture(char **content, char **strs, int arr[6]);

#endif