/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:25:48 by tandre            #+#    #+#             */
/*   Updated: 2023/01/09 01:48:57 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3D.h"

int			is_cmp(char *s1, char *s2);
int			get_count_gnl(char *file);
int			notify(int e, void *p);
void		moove(t_win	*c, int key);
t_vector	rotate_v(t_win *c, int d);
void		init_vectors_helper(t_win	*cube, t_parse *parse);
void		fill_img_helper(t_win *cube, int size_tmp);

#endif