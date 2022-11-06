/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_i_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:28:47 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 19:29:57 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

static void	malloc_i_map(t_state *cub)
{
	int	height;
	int	i;

	height = 0;
	while (cub->map.map[height])
		height++;
	cub->map.i_map = malloc(sizeof(int **) * height);
	i = -1;
	while (++i < height)
		cub->map.i_map[i] = malloc(sizeof(int *) * ft_strlen(cub->map.map[i]));
}

void	init_i_map(t_state *cub)
{
	int	i;
	int	j;

	malloc_i_map(cub);
	i = -1;
	while (cub->map.map[++i])
	{
		j = -1;
		while (cub->map.map[i][++j])
		{
			if (cub->map.map[i][j] == ' ')
				cub->map.i_map[i][j] = 2;
			else if (ft_strrchr("NSEW", cub->map.map[i][j]))
				cub->map.i_map[i][j] = 0;
			else if (cub->map.map[i][j] == '0')
				cub->map.i_map[i][j] = 0;
			else if (cub->map.map[i][j] == '1')
				cub->map.i_map[i][j] = 1;
		}
	}
}
