/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandre <tandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:04:38 by arastell          #+#    #+#             */
/*   Updated: 2023/01/09 00:23:33 by tandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	while (tmp_s1[i] && tmp_s2[i] && tmp_s1[i] == tmp_s2[i])
		i++;
	if (tmp_s1[i] != tmp_s2[i])
		return (tmp_s1[i] - tmp_s2[i]);
	return (0);
}
