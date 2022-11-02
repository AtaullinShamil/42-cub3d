/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:15:10 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 17:44:23 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"

int	esc(t_state *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	free_all(cub);
	exit(0);
}

void	set_the_teture(char *xpm, t_img_info *info, t_state *cub)
{
	int	x;
	int	y;

	info->img = mlx_xpm_file_to_image(cub->mlx, xpm, &x, &y);
	info->adr = (int *)mlx_get_data_addr(info->img, &info->bpp, &info->size_line, &info->endian);
}

void	set_all_textures(t_state *cub)
{
	set_the_teture(cub->sprites.c_ea, &cub->img.ea, cub);
	set_the_teture(cub->sprites.c_we, &cub->img.we, cub);
	set_the_teture(cub->sprites.c_no, &cub->img.no, cub);
	set_the_teture(cub->sprites.c_so, &cub->img.so, cub);
}

void	draw_ceiling_and_floor(t_state *cub)
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

int	main(int argc, char **argv)
{
	t_state	cub;

	parsing(argc, argv, &cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, RES_X, RES_Y, "cub3D");

	set_all_textures(&cub);
	cub.img.window.img = mlx_new_image(cub.mlx, RES_X, RES_Y);
	cub.img.window.adr = (int *)mlx_get_data_addr(cub.img.window.img, &cub.img.window.bpp, &cub.img.window.size_line, &cub.img.window.endian);
	draw_ceiling_and_floor(&cub);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img.window.img, 0, 0);

	mlx_hook(cub.win, 17, 0, esc, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
