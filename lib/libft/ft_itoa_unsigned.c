/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:58:31 by arastell          #+#    #+#             */
/*   Updated: 2022/11/28 09:04:50 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (n >= 0 && n < 10)
		i++;
	return (i);
}

static void	ft_strcat_c(char *s, char c)
{
	size_t	size;

	size = ft_strlen(s);
	s[size] = c;
	s[size + 1] = '\0';
}

static void	ft_recursive_itoa(char *s, unsigned int n)
{
	if (n > 9)
	{
		ft_recursive_itoa(s, n / 10);
		ft_recursive_itoa(s, n % 10);
	}
	else
		ft_strcat_c(s, n + '0');
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_len(n) + 1));
	if (!tmp)
		return (0);
	tmp[0] = '\0';
	ft_recursive_itoa(tmp, n);
	return (tmp);
}
