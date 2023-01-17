/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:38:58 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 09:59:17 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	long int	new_n;
	int			i;

	new_n = (long int) n;
	i = 0;
	if (new_n < 0)
	{
		new_n *= -1;
		i++;
	}
	while (new_n > 9)
	{
		new_n /= 10;
		i++;
	}
	if (new_n >= 0 && new_n < 10)
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

static void	ft_recursive_itoa(char *s, long int n)
{
	if (n < 0)
	{
		ft_strcat_c(s, '-');
		ft_recursive_itoa(s, n * -1);
	}
	else if (n > 9)
	{
		ft_recursive_itoa(s, n / 10);
		ft_recursive_itoa(s, n % 10);
	}
	else
		ft_strcat_c(s, n + '0');
}

char	*ft_itoa(int n)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_len(n) + 1));
	if (!tmp)
		return (0);
	tmp[0] = '\0';
	ft_recursive_itoa(tmp, (long int) n);
	return (tmp);
}
