/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:10:23 by arastell          #+#    #+#             */
/*   Updated: 2023/01/06 17:58:33 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_color(char *s_r, char *s_g, char *s_b)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(s_r);
	g = ft_atoi(s_g);
	b = ft_atoi(s_b);
	return (r << 16 | g << 8 | b);
}
