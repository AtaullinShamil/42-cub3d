/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:42:26 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/30 18:43:18 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	cord_repits(char **map)
{
	int	i;
	int	j;
	int	coordinate;

	i = -1;
	coordinate = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
				coordinate++;
			if (coordinate > 1)
			{
				put_error(ERR_M_C, NULL);
				return (1);
			}
		}
	}
	return (0);

}

static int	parse_symbols(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strrchr(M_S, map[i][j]) == NULL)
			{
				put_error(ERR_M_S, map[i]);
				return (1);
			}
		}
	}
	return (0);
}

void	parse_map(char **map)
{
	if (parse_symbols(map))
		exit(1);
	if (cord_repits(map))
		exit(1);
}
