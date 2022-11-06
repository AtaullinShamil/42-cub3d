/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:09:05 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 20:34:15 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void static	draw_pixel(t_state *data, int i, int j, int color)
{
	int		y;
	int		x;
	char	*dest;

	y = RES_Y * 0.01 * i;
	while (y < RES_Y * 0.01 * (i + 1))
	{
		x = RES_X * 0.01 * j;
		while (x < RES_X * 0.01 * (j + 1))
		{
			dest = (char *)data->img.window.adr + ((y + 10) * \
			data->img.window.size_line + (x + 10) * (data->img.window.bpp / 8));
			*(unsigned int *)dest = color;
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_state *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(data->map.map[i]))
		{
			if (data->map.i_map[i][j] == 1)
				draw_pixel(data, i, j, 65407);
			else
				draw_pixel(data, i, j, 789516);
			j++;
		}
		i++;
	}
	draw_pixel(data, data->player.x_pos, data->player.y_pos, 7905);
}
