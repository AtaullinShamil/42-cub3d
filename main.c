/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:15:10 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 18:56:33 by ntojamur         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_state	cub;

	parsing(argc, argv, &cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, RES_X, RES_Y, "cub3D");
	set_all_textures(&cub);

	render(&cub);
	mlx_hook(cub.win, 17, 0, esc, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
