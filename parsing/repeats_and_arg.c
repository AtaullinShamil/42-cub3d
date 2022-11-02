/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeats_and_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:04:54 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 16:11:06 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	count_quantity(t_state *cub)
{
	int	i;

	i = 0;
	init_amount(&cub->data);
	while (i < 6)
	{
		if (ft_strncmp(cub->info[i][0], "EA", 3) == 0)
			cub->data.n_ea++;
		else if (ft_strncmp(cub->info[i][0], "WE", 3) == 0)
			cub->data.n_we++;
		else if (ft_strncmp(cub->info[i][0], "NO", 3) == 0)
			cub->data.n_no++;
		else if (ft_strncmp(cub->info[i][0], "SO", 3) == 0)
			cub->data.n_so++;
		else if (ft_strncmp(cub->info[i][0], "F", 2) == 0)
			cub->data.n_f++;
		else if (ft_strncmp(cub->info[i][0], "C", 2) == 0)
			cub->data.n_c++;
		i++;
	}
}

void	parse_repeats(t_state *cub)
{
	count_quantity(cub);
	if (cub->data.n_c != 1 || cub->data.n_f != 1 || cub->data.n_ea != 1 \
	|| cub->data.n_we != 1 || cub->data.n_no != 1 || cub->data.n_so != 1)
	{
		put_error(ERR_R, NULL);
		free_all(cub);
		exit(1);
	}
}

static void	split_color(char *color, int	*place)
{
	char	**split;

	split = ft_split(color, ',');
	*place = (ft_atoi(split[0]) << 16) | (ft_atoi(split[1]) << 8) \
	| (ft_atoi(split[2]) << 0);
	free_split(split);
}

void	init_arg(t_state *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(cub->info[i][0], "EA", 3) == 0)
			cub->c_ea = cub->info[i][1];
		else if (ft_strncmp(cub->info[i][0], "WE", 3) == 0)
			cub->c_we = cub->info[i][1];
		else if (ft_strncmp(cub->info[i][0], "NO", 3) == 0)
			cub->c_no = cub->info[i][1];
		else if (ft_strncmp(cub->info[i][0], "SO", 3) == 0)
			cub->c_so = cub->info[i][1];
		else if (ft_strncmp(cub->info[i][0], "F", 2) == 0)
			split_color(cub->info[i][1], &cub->floor);
		else if (ft_strncmp(cub->info[i][0], "C", 2) == 0)
			split_color(cub->info[i][1], &cub->ceiling);
		i++;
	}
}
