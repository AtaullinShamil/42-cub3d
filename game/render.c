/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:54:43 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 18:30:41 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	draw_ceiling_and_floor(t_state *cub)
{
	unsigned int		*dst;
	int					i;

	dst = (unsigned int *)cub->img.window.adr;
	i = RES_X * RES_Y / 2 + 1;
	while (--i > 0)
	*dst++ = cub->ceiling;
	i = RES_X * RES_Y / 2 + 1;
	while (--i > 0)
	*dst++ = cub->floor;
}

void	init_start_params(t_state *cub, int i)
{
	cub->ray.camera_x = 2 * i / (double)RES_X - 1;
	cub->ray.ray_dir_x = cub->player.dir_x + cub->player.plane_x \
	* cub->ray.camera_x;
	cub->ray.ray_dir_y = cub->player.dir_y + cub->player.plane_y \
	* cub->ray.camera_x;
	cub->ray.map_x = (int)cub->player.x_pos;
	cub->ray.map_y = (int)cub->player.y_pos;
	if (cub->ray.ray_dir_x == 0)
		cub->ray.delta_dist_x = 1e30;
	else
		cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
	if (cub->ray.ray_dir_y == 0)
		cub->ray.delta_dist_y = 1e30;
	else
		cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
}

void	calculate_steps(t_state	*data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.x_pos - data->ray.map_x) * \
		data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->player.x_pos) * \
		data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.y_pos - data->ray.map_y) * \
		data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->player.y_pos) * \
		data->ray.delta_dist_y;
	}
}

void	dda_algoritm(t_state	*data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map.i_map[data->ray.map_x][data->ray.map_y] == 1)
			data->ray.hit = 1;
	}
}

void	draw_func_helper(t_state *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (data->ray.side_dist_x - \
		data->ray.delta_dist_x);
	else
		data->ray.perp_wall_dist = (data->ray.side_dist_y - \
		data->ray.delta_dist_y);
	data->ray.line_height = (int)(RES_Y / data->ray.perp_wall_dist);
		data->ray.draw_start = -data->ray.line_height / 2 + RES_Y / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + RES_Y / 2;
	if (data->ray.draw_end >= RES_Y)
		data->ray.draw_end = RES_Y - 1;
}

void	prepare_func(t_state	*data)
{
	double	wall_x;

	if (data->ray.side == 0)
		wall_x = data->player.y_pos + data->ray.perp_wall_dist \
		* data->ray.ray_dir_y;
	else
		wall_x = data->player.x_pos + data->ray.perp_wall_dist \
		* data->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	data->wall.tex_x = (int)(wall_x * (double)T_SIZE);
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		data->wall.tex_x = T_SIZE - data->wall.tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		data->wall.tex_x = T_SIZE - data->wall.tex_x - 1;
	data->wall.step = 1.0 * T_SIZE / data->ray.line_height;
	data->wall.tex_pos = (data->ray.draw_start - RES_Y / 2 + \
	data->ray.line_height / 2) * data->wall.step;
}

int	texturing(t_state *data, unsigned int *color)
{
	if (data->ray.side == 0)
	{
		if (data->ray.ray_dir_x >= 0)
			*color = ((unsigned int *)data->img.ea.adr)[T_SIZE \
			* data->wall.tex_y + data->wall.tex_x];
		else
			*color = ((unsigned int *)data->img.we.adr)[T_SIZE \
			* data->wall.tex_y + data->wall.tex_x];
	}
	else
	{
		if (data->ray.ray_dir_y >= 0)
			*color = ((unsigned int *)data->img.so.adr)[T_SIZE \
			* data->wall.tex_y + data->wall.tex_x];
		else
			*color = ((unsigned int *)data->img.no.adr)[T_SIZE \
			* data->wall.tex_y + data->wall.tex_x];
	}
	return (*color);
}


void	draw_textures(t_state *data, int i)
{
	int				j;
	char			*dest;
	unsigned int	color;

	j = data->ray.draw_start;
	prepare_func(data);
	while (j <= data->ray.draw_end)
	{
		data->wall.tex_y = (int)data->wall.tex_pos & (T_SIZE - 1);
		data->wall.tex_pos += data->wall.step;
		color = texturing(data, &color);
		dest = (char *)data->img.window.adr + (j * data->img.window.size_line + \
		i * (data->img.window.bpp / 8));
		*(unsigned int *)dest = color;
		j++;
	}
}

static	void draw_func(t_state *cub)
{
	int	i;

	i = -1;
	while (++i < RES_X)
	{
		init_start_params(cub, i);
		calculate_steps(cub);
		dda_algoritm(cub);
		draw_func_helper(cub);
		draw_textures(cub, i);
	}
}

void	render(t_state *cub)
{
	cub->img.window.img = mlx_new_image(cub->mlx, RES_X, RES_Y);
	cub->img.window.adr = (int *)mlx_get_data_addr(cub->img.window.img, \
		&cub->img.window.bpp, &cub->img.window.size_line, &cub->img.window.endian);
	draw_ceiling_and_floor(cub);
	draw_func(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.window.img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img.window.img);
}
