/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 00:58:42 by tandre            #+#    #+#             */
/*   Updated: 2023/01/10 12:54:22 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include "cub3D.h"

void	free_split(char **s);
void	free_parsing(t_parse *parse);
void	free_cube(t_win *cube);

#endif