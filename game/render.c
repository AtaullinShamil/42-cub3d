/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:54:43 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 18:59:49 by ntojamur         ###   ########.fr       */
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

void	render(t_state *cub)
{
	cub->img.window.img = mlx_new_image(cub->mlx, RES_X, RES_Y);
	cub->img.window.adr = (int *)mlx_get_data_addr(cub->img.window.img, \
		&cub->img.window.bpp, &cub->img.window.size_line, &cub->img.window.endian);
	draw_ceiling_and_floor(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.window.img, 0, 0);
}
