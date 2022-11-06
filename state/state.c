/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:55:27 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 19:54:07 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	init_amount(t_amount *data)
{
	data->n_c = 0;
	data->n_f = 0;
	data->n_no = 0;
	data->n_ea = 0;
	data->n_so = 0;
	data->n_we = 0;
}

static void	set_the_teture(char *xpm, t_img_info *info, t_state *cub)
{
	int	x;
	int	y;

	info->img = mlx_xpm_file_to_image(cub->mlx, xpm, &x, &y);
	info->adr = (int *)mlx_get_data_addr(info->img, &info->bpp, \
	&info->size_line, &info->endian);
}

void	set_all_textures(t_state *cub)
{
	set_the_teture(cub->sprites.c_ea, &cub->img.ea, cub);
	set_the_teture(cub->sprites.c_we, &cub->img.we, cub);
	set_the_teture(cub->sprites.c_no, &cub->img.no, cub);
	set_the_teture(cub->sprites.c_so, &cub->img.so, cub);
}
