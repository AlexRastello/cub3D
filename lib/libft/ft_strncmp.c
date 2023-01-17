/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:28:03 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 10:19:49 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (tmp_s1[i] && tmp_s2[i] && tmp_s1[i] == tmp_s2[i] && i < (n - 1))
		i++;
	if (tmp_s1[i] != tmp_s2[i])
		return (tmp_s1[i] - tmp_s2[i]);
	return (0);
}
