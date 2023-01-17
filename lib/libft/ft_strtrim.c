/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:35:13 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 10:50:01 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < j && ft_strchr(set, s1[j]))
		j--;
	tmp = malloc(sizeof(char) * ((j - i) + 2));
	if (!tmp)
		return (0);
	s1 += i;
	while (k <= (j - i))
	{
		tmp[k] = (char) s1[k];
		k++;
	}
	tmp[k] = '\0';
	return (tmp);
}
