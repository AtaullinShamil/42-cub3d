/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_wasd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:46:20 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 18:50:46 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_w(t_state	*data)
{
	if (data->map.i_map[(int)(data->player.x_pos + data->player.dir_x * 0.65)] \
	[(int)data->player.y_pos] == 0)
		data->player.x_pos += data->player.dir_x * MS;
	if (data->map.i_map[(int)(data->player.x_pos)][(int)(data->player.y_pos + \
	data->player.dir_y * 0.65)] == 0)
		data->player.y_pos += data->player.dir_y * MS;
	render(data);
}

void	move_a(t_state	*data)
{
	if (data->map.i_map[(int)(int)(data->player.x_pos - data->player.plane_x \
	* 0.65)][(int)data->player.y_pos] == 0)
		data->player.x_pos -= data->player.plane_x * MS;
	if (data->map.i_map[(int)data->player.x_pos][(int)(data->player.y_pos - \
	data->player.plane_y * 0.65)] == 0)
		data->player.y_pos -= data->player.plane_y * MS;
	render(data);
}

void	move_s(t_state	*data)
{
	if (data->map.i_map[(int)(data->player.x_pos - data->player.dir_x * 0.65)] \
	[(int)data->player.y_pos] == 0)
		data->player.x_pos -= data->player.dir_x * MS;
	if (data->map.i_map[(int)(data->player.x_pos)][(int)(data->player.y_pos - \
	data->player.dir_y * 0.65)] == 0)
		data->player.y_pos -= data->player.dir_y * MS;
	render(data);
}

void	move_d(t_state	*data)
{
	if (data->map.i_map[(int)(data->player.x_pos + \
	data->player.plane_x * 0.65)][(int)data->player.y_pos] == 0)
		data->player.x_pos += data->player.plane_x * MS;
	if (data->map.i_map[(int)data->player.x_pos][(int)(data->player.y_pos + \
	data->player.plane_y * 0.65)] == 0)
		data->player.y_pos += data->player.plane_y * MS;
	render(data);
}
