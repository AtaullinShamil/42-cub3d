/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:15:10 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 05:09:02 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"

void	rgb_to_hex(t_state *cub)
{
	cub->floor_color = (1 << 24 | cub->floor[0] << 16 | cub->floor[1] << 8 | cub->floor[2]);
	cub->ceiling_color = (1 << 24 | cub->ceiling[0] << 16 | cub->ceiling[1] << 8 | cub->ceiling[2]);
}

// void	set_the_teture(char *xpm, t_img_info *info, t_state *cub)
// {
// 	int x;
// 	int y;
// 	int i;

// 	printf("as11111\n");
// 	info->img = mlx_xpm_file_to_image(cub->mlx, xpm, &info->x, &info->y);
// 	printf("22222\n");
// 	info->adr = (int *)mlx_get_data_addr(info->img, &x, &y, &i);
// }

// void	set_all_textures(t_state *cub)
// {
// 	printf("as1\n");
// 	set_the_teture(cub->c_ea, &cub->img.ea, cub);
// 	printf("as\n");
// 	set_the_teture(cub->c_we, &cub->img.we, cub);
// 	set_the_teture(cub->c_no, &cub->img.no, cub);
// 	set_the_teture(cub->c_so, &cub->img.so, cub);
// }

void	draw_celling_and_floor(t_state *cub)
{
	unsigned int		*dst;
	int					i;

	dst = (unsigned int *)cub->img.data_addr;
	i = RES_X * RES_Y / 2 + 1;
	while (--i > 0)
	*dst++ = cub->ceiling_color;
	i = RES_X * RES_Y / 2 + 1;
	while (--i > 0)
	*dst++ = cub->floor_color;
}

int	main(int argc, char **argv)
{
	t_state	cub;

	parsing(argc, argv, &cub);
	rgb_to_hex(&cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, RES_X, RES_Y, "cub3D");

	//set_all_textures(&cub);
	cub.img.img_ptr = mlx_new_image(cub.mlx, RES_X, RES_Y);
	cub.img.data_addr = (int *)mlx_get_data_addr(cub.img.img_ptr, &cub.img.bpp, &cub.img.size_line, &cub.img.endian);
	draw_celling_and_floor(&cub);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img.img_ptr, 0, 0);

	mlx_loop(cub.mlx);
	free_all(&cub);
	return (0);
}
