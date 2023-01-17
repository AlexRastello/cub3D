/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:56:52 by tandre            #+#    #+#             */
/*   Updated: 2023/01/09 00:57:13 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3D.h"

t_parse	*parsing(char *path);
char	**get_infos(char *file);
char	**get_map(char *file);
char	**update_map(char **map);
void	fill_infos(char *file, t_parse *parse);
void	format_map(char **map);

#endif