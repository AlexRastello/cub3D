/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:18:52 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 10:01:37 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy_dup(char *dst, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tmp)
		return (0);
	ft_strcpy_dup(tmp, s);
	return (tmp);
}
