/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:15:10 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 16:09:56 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"

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

	//set_all_textures(&cub);
	cub.img.img_ptr = mlx_new_image(cub.mlx, RES_X, RES_Y);
	cub.img.data_addr = (int *)mlx_get_data_addr(cub.img.img_ptr, &cub.img.bpp, &cub.img.size_line, &cub.img.endian);
	draw_celling_and_floor(&cub);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img.img_ptr, 0, 0);

	mlx_loop(cub.mlx);
	free_all(&cub);
	return (0);
}
