/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:12:23 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/01 06:05:05 by ntojamur         ###   ########.fr       */
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
				break;
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
				break;
			x--;
		}
		y++;
	}
	return (0);
}

int	check_walls(char **map)
{
	if (check_walls_left_to_right(map) || \
		check_walls_right_to_left(map))
	{
		put_error(ERR_M_W, NULL);
		return (1);
	}
	return (0);
}
