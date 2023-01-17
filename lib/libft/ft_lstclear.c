/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:18:56 by arastell          #+#    #+#             */
/*   Updated: 2022/11/10 10:54:00 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*tmp;
	t_list	*elem;

	if (lst && (*del) != NULL)
	{
		tmp = 0;
		elem = *lst;
		while (elem)
		{
			tmp = elem->next;
			ft_lstdelone(elem, (*del));
			elem = tmp;
		}
		*lst = 0;
	}
}
