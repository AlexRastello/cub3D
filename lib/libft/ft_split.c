/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:04:52 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 10:47:42 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_items(char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[j + i] != c && s[j + i] != '\0')
				j++;
			split[k] = malloc(sizeof(char) * (j + 1));
			if (!split[k])
				return (0);
			ft_strlcpy(split[k], s + i, j + 1);
			k++;
			i += j;
		}
	}
	split[k] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**tmp;
	size_t	i;
	size_t	count_sep;

	i = 0;
	count_sep = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			count_sep++;
		i++;
	}
	tmp = malloc(sizeof(char *) * (count_sep + 1));
	if (!tmp)
		return (0);
	if (!ft_malloc_items(tmp, s, c))
		return (0);
	return (tmp);
}
