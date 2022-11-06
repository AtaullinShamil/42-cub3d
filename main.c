/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:15:10 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 18:03:54 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"

void	init_i_map(t_state *cub)
{
	int	height;
	int	i;
	int j;

	i = 0;
	height = 0;
	while(cub->map.map[height])
		height++;
	cub->map.i_map = malloc(sizeof(int **) * height);
	while (i < height)
	{
		cub->map.i_map[i] = malloc(sizeof(int *) * ft_strlen(cub->map.map[i]));
		i++;
	}
	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == ' ')
				cub->map.i_map[i][j] = 2;
			else if (ft_strrchr("NSEW", cub->map.map[i][j]))
				cub->map.i_map[i][j] = 0;
			else if (cub->map.map[i][j] == '0')
				cub->map.i_map[i][j] = 0;
			else if (cub->map.map[i][j] == '1')
				cub->map.i_map[i][j] = 1;
			j++;
		}
		i++;
	}
}

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
	mlx_hook(cub.win, 17, 0, esc, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
