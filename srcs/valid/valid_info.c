/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arastell <arastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:08:58 by arastell          #+#    #+#             */
/*   Updated: 2023/01/05 07:08:59 by arastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	is_good_color(char *line)
{
	char	**strs;
	int		i;
	int		to_ret;

	to_ret = 1;
	i = 0;
	strs = ft_split(line, ',');
	while (strs[i])
	{
		if (ft_atoi(strs[i]) < 0 || ft_atoi(strs[i]) > 255)
			to_ret = 0;
		i++;
	}
	free_split(strs);
	if (i != 3)
		return (0);
	return (to_ret);
}

static int	is_good_color_strs(char *r, char *g, char *b)
{
	char	*trim;

	trim = ft_strtrim(r, ", ");
	if (ft_atoi(trim) < 0 || ft_atoi(trim) > 255)
	{
		free(trim);
		return (0);
	}
	free(trim);
	trim = ft_strtrim(g, ", ");
	if (ft_atoi(trim) < 0 || ft_atoi(trim) > 255)
	{
		free(trim);
		return (0);
	}
	free(trim);
	trim = ft_strtrim(b, ", ");
	if (ft_atoi(trim) < 0 || ft_atoi(trim) > 255)
	{
		free(trim);
		return (0);
	}
	free(trim);
	return (1);
}

static void	check_color(int i, char **strs, char **content)
{
	if (i > 2)
	{
		if (!is_good_color_strs(strs[1], strs[2], strs[3]))
			error_valid(content, strs, "Not a valid format color");
	}
	else
	{
		if (!is_good_color(strs[1]))
			error_valid(content, strs, "Not a valid format color");
	}		
}

static void	valid_color(char **content, char **strs, int arr[6])
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2 && i != 4)
		error_valid(content, strs, "Not a valid format color");
	if (is_contain_double(strs[0], arr))
		error_valid(content, strs, "Double color present in file");
	if (!is_only_color(strs))
		error_valid(content, strs, "Not a valid format color");
	if (!ft_strcmp(strs[0], "F"))
		arr[4] = 1;
	if (!ft_strcmp(strs[0], "C"))
		arr[5] = 1;
	if (!is_cmp(strs[0], "F") && !is_cmp(strs[0], "C"))
		error_valid(content, strs, "Not a valid id format color");
	check_color(i, strs, content);
}

int	is_good_infos(char *file)
{
	char	**content;
	char	**strs;
	int		i;
	int		arr[6];

	fill_valid_arr(arr);
	i = 0;
	content = get_infos(file);
	while (content[i])
	{
		strs = ft_split(content[i], ' ');
		if (!strs[1])
			error_valid(content, strs, "Arguments required for informations");
		if (ft_strlen(strs[0]) == 1)
			valid_color(content, strs, arr);
		else if (ft_strlen(strs[0]) == 2)
			valid_texture(content, strs, arr);
		else if (ft_strlen(strs[0]) > 2)
			error_valid(content, strs, "Don't know this information");
		free_split(strs);
		i++;
	}
	free_split(content);
	return (check_valid_arr(arr));
}
