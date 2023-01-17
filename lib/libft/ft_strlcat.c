/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:21 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 11:41:29 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_initial;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	dst_initial = ft_strlen(dst);
	if (i + dst_initial < size -1)
	{
		while (src[i] && (i + dst_initial) < (size - 1))
		{
			dst[i + dst_initial] = src[i];
			i++;
		}
		dst[i + dst_initial] = '\0';
	}
	if (dst_initial > size)
		return (ft_strlen(src) + size);
	return (dst_initial + ft_strlen(src));
}
