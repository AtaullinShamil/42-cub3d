/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:46:21 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 22:52:34 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_names(char **split, char *string)
{
	if (ft_strncmp(split[0], "EA", 3) && ft_strncmp(split[0], "WE", 3) && \
	ft_strncmp(split[0], "NO", 3) && ft_strncmp(split[0], "SO", 3) && \
	ft_strncmp(split[0], "F", 2) && ft_strncmp(split[0], "C", 2))
	{
		put_error(S_U, string);
		return (1);
	}
	return (0);
}

static int	check_size(char **split, char *string)
{
	if (split_size(split) != 2)
	{
		put_error(S_A, string);
		return (1);
	}
	return (0);
}

static int	check_xpm(char **split, char *string)
{
	if (!ft_strncmp(split[0], "EA", 3) || !ft_strncmp(split[0], "WE", 3) || \
	!ft_strncmp(split[0], "NO", 3) || !ft_strncmp(split[0], "SO", 3))
	{
		if (ft_strncmp(ft_strrchr(split[1], '.'), XPM, 5))
		{
			put_error(S_XPM, string);
			return (1);
		}
	}
	return (0);
}

static int	check_string(t_state *cub, char *string, int i)
{
	char	**split;

	cub->info[i] = ft_split(string, ' ');
	split = cub->info[i];
	if (check_names(split, string))
		return (1);
	if (check_size(split, string))
		return (1);
	if (check_xpm(split, string))
		return (1);
	if (!ft_strncmp(split[0], "F", 2) || !ft_strncmp(split[0], "C", 2))
		if (check_rgb(split, string))
			return (1);
	return (0);
}

void	parse_strings(t_state *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (check_string(cub, cub->file[i], i))
			exit(1);
		i++;
	}
}
