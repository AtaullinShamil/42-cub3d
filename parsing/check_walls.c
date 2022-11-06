/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:12:23 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 23:05:00 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_walls_left_to_right(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != ' ')
				return (1);
			else
				break ;
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_walls_right_to_left(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = ft_strlen(map[y]) - 1;
		while (x > -1)
		{
			if (map[y][x] != '1' && map[y][x] != ' ')
				return (1);
			else
				break ;
			x--;
		}
		y++;
	}
	return (0);
}

static int	check_up_and_down(char **map)
{
	int	x;
	int	y;

	y = split_size(map);
	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' && map[0][x] != ' ')
			return (1);
		x++;
	}
	x = 0;
	while (map[y - 1][x])
	{
		if (map[y - 1][x] != '1' && map[y - 1][x] != ' ')
			return (1);
		x++;
	}
	return (0);
}

static int	check_map_all(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (++y < split_size(map) - 1)
	{
		x = 0;
		while (x++ < (int)ft_strlen(map[y]) - 2)
		{
			if (map[y][x] == '0')
				if (ft_strchr("NSEW01", map[y][x + 1]) == NULL || \
				ft_strchr("NSEW01", map[y][x - 1]) == NULL || \
				ft_strchr("NSEW01", map[y + 1][x]) == NULL || \
				ft_strchr("NSEW01", map[y - 1][x]) == NULL)
					return (1);
			if (ft_strchr("NSEW", map[y][x]) != NULL)
				if (ft_strchr("01", map[y][x + 1]) == NULL || \
					ft_strchr("01", map[y][x - 1]) == NULL || \
					ft_strchr("01", map[y + 1][x]) == NULL || \
					ft_strchr("01", map[y - 1][x]) == NULL)
					return (1);
		}
	}
	return (0);
}

int	check_walls(char **map)
{
	if (check_walls_left_to_right(map) || \
	check_walls_right_to_left(map) || \
	check_up_and_down(map))
	{
		put_error(ERR_M_W, NULL);
		return (1);
	}
	if (check_map_all(map))
	{
		put_error(ERR_M_A, NULL);
		return (1);
	}
	return (0);
}
