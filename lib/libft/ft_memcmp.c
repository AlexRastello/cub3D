/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:44 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 10:10:57 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*tmp_s1;
	unsigned const char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned const char *) s1;
	tmp_s2 = (unsigned const char *) s2;
	while (n)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
		n--;
	}
	return (0);
}
