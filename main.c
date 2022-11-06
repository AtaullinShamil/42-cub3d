/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:15:10 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 22:44:43 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_state	cub;

	parsing(argc, argv, &cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, RES_X, RES_Y, "cub3D");
	set_all_textures(&cub);
	init_i_map(&cub);
	init_player(&cub);
	render(&cub);
	mlx_hook(cub.win, 2, 0, game, &cub);
	mlx_hook(cub.win, 2, 0, game, &cub);
	mlx_mouse_move(cub.win, RES_X / 2, RES_Y / 2);
	mlx_hook(cub.win, 6, 0, mouse_hook, &cub);
	mlx_hook(cub.win, 17, 0, esc, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
