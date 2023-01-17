/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:52 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 11:44:31 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strlen_unsigned(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*tmp;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	if (ft_strlen_unsigned(s) < start)
	{
		tmp = malloc(sizeof(char) * 1);
		tmp[0] = '\0';
		return (tmp);
	}
	if (len > ft_strlen_unsigned(s))
		tmp = malloc(sizeof(char) * (ft_strlen_unsigned(s) + 1));
	else
		tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	while (s[start + i] && i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
