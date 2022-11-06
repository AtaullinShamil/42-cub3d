/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:00:27 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 22:50:36 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	esc(t_state *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	free_all(cub);
	exit(0);
}

void	move_right(t_state	*data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(RS) - \
	data->player.dir_y * sin(RS);
	data->player.dir_y = old_dir_x * sin(RS) + data->player.dir_y * cos(RS);
	data->player.plane_x = data->player.plane_x * cos(RS) - \
	data->player.plane_y * sin(RS);
	data->player.plane_y = old_plane_x * sin(RS) + data->player.plane_y \
	* cos(RS);
	render(data);
}

void	move_left(t_state	*data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(-RS) - \
	data->player.dir_y * sin(-RS);
	data->player.dir_y = old_dir_x * sin(-RS) + \
	data->player.dir_y * cos(-RS);
	data->player.plane_x = data->player.plane_x * cos(-RS) - \
	data->player.plane_y * sin(-RS);
	data->player.plane_y = old_plane_x * sin(-RS) + \
	data->player.plane_y * cos(-RS);
	render(data);
}

int	mouse_hook(int x, int y, t_state *data)
{
	(void) y;
	if (x > data->player.mouse_x)
		move_right(data);
	else if (x < data->player.mouse_x)
		move_left(data);
	data->player.mouse_x = x;
	return (0);
}

int	game(int key, t_state *cub)
{
	if (key == ESC)
		esc(cub);
	else if (key == W_KEY)
		move_w(cub);
	else if (key == A_KEY)
		move_a(cub);
	else if (key == S_KEY)
		move_s(cub);
	else if (key == D_KEY)
		move_d(cub);
	else if (key == RIGHT_KEY)
		move_right(cub);
	else if (key == LEFT_KEY)
		move_left(cub);
	else if (key == 46)
	{
		if (cub->map_flag == 0)
			cub->map_flag = 1;
		else
			cub->map_flag = 0;
		render(cub);
	}
	return (0);
}
