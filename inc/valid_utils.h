/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:23:53 by tandre            #+#    #+#             */
/*   Updated: 2023/01/09 00:25:24 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_UTILS_H
# define VALID_UTILS_H

# include "cub3D.h"

int		is_empty(char *line);
int		is_map(char *line);
int		is_infos(char *line);
int		check_valid_boolean(int arr[6]);
void	fill_valid_boolean(int arr[6]);

#endif