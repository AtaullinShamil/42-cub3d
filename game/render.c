/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:54:43 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 20:16:59 by ntojamur         ###   ########.fr       */
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

static void	init_start_params(t_state *cub, int i)
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

static void	calculate_steps(t_state	*data)
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

static void	draw_func(t_state *cub)
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
		&cub->img.window.bpp, &cub->img.window.size_line, \
		&cub->img.window.endian);
	draw_ceiling_and_floor(cub);
	draw_func(cub);
	draw_mini_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.window.img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img.window.img);
}
