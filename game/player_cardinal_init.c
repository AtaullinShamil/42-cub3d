/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_cardinal_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:53:54 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 18:51:44 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	west(t_state *cub, int i, int j)
{
	cub->map.map[i][j] = 0;
	cub->map.n++;
	cub->player.x_pos = i;
	cub->player.y_pos = j;
	cub->player.dir_x = 0;
	cub->player.dir_y = -1;
	cub->player.plane_x = 0.66;
	cub->player.plane_y = 0;
}

static void	east(t_state *cub, int i, int j)
{
	cub->map.map[i][j] = 0;
	cub->map.s++;
	cub->player.x_pos = i;
	cub->player.y_pos = j;
	cub->player.dir_x = 0;
	cub->player.dir_y = 1;
	cub->player.plane_x = -0.66;
	cub->player.plane_y = 0;
}

static void	north(t_state *cub, int i, int j)
{
	cub->map.map[i][j] = 0;
	cub->map.w++;
	cub->player.x_pos = i;
	cub->player.y_pos = j;
	cub->player.dir_x = -1;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = -0.66;
}

static void	sourth(t_state *cub, int i, int j)
{
	cub->map.map[i][j] = 0;
	cub->map.e++;
	cub->player.x_pos = i;
	cub->player.y_pos = j;
	cub->player.dir_x = 1;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = 0.66;
}

void	init_player(t_state *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map.map[++i])
	{
		j = -1;
		while (cub->map.map[i][++j])
		{
			if (cub->map.map[i][j] == 'S')
				sourth(cub, i, j);
			if (cub->map.map[i][j] == 'N')
				north(cub, i, j);
			if (cub->map.map[i][j] == 'E')
				east(cub, i, j);
			if (cub->map.map[i][j] == 'W')
				west(cub, i, j);
		}
	}
}
