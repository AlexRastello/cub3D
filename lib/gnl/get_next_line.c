/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:33:07 by arastell          #+#    #+#             */
/*   Updated: 2022/11/28 14:03:29 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	if (buffer[0] == '\0')
		return (0);
	line = malloc(sizeof(char) * (ft_count_malloc(buffer) + 1));
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_del_line(char *buffer)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, buffer + i, ft_strlen(buffer));
	free(buffer);
	return (tmp);
}

char	*ft_join_buff(char *dst, char *src)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!dst || !src)
		return (0);
	tmp = malloc(sizeof(char) * (ft_strlen(dst) + BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	i = ft_strlcpy(tmp, dst, ft_strlen(dst) + 1);
	ft_strlcpy(tmp + i, src, ft_strlen(src) + 1);
	free(dst);
	return (tmp);
}

char	*ft_gnl_read(int fd, char *buffer)
{
	char	tmp_buffer[BUFFER_SIZE + 1];
	int		res;

	res = 1;
	while (res != 0 && !ft_contain(buffer, '\n'))
	{
		res = read(fd, tmp_buffer, BUFFER_SIZE);
		if (res == -1)
			return (0);
		tmp_buffer[res] = '\0';
		buffer = ft_join_buff(buffer, tmp_buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer[fd])
			return (0);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = ft_gnl_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_del_line(buffer[fd]);
	return (line);
}
