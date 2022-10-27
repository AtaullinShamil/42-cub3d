/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:50 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/27 18:06:36 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "stdio.h"

static void	parse_conf(int argc, char **argv)
{
	int	fd;
	if (argc == 1)
		put_error_exit(CF_N, NULL);
	if (argc > 2)
		put_error_exit(CF_TMA, NULL);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), CUB, 5))
		put_error_exit(CF_CUB, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		put_error_exit(F_N, argv[1]);
	close(fd);
}

static void check_string(t_state *cub, char *string)
{
	char **split;

	split = ft_split(string, ' ');
	if (ft_strncmp(split[0], "EA", 3) && ft_strncmp(split[0], "WE", 3) && \
	ft_strncmp(split[0], "NO", 3) && ft_strncmp(split[0], "SO", 3) && \
	ft_strncmp(split[0], "F", 2) && ft_strncmp(split[0], "C", 2))
	{
		put_error(S_U, string);
		free_split(split);
		free_split(cub->file);
		exit(1);
	}
	if (split_size(split) != 2)
	{
		put_error(S_A, string);
		free_split(split);
		free_split(cub->file);
		exit(1);
	}
	if (!ft_strncmp(split[0], "EA", 3) || !ft_strncmp(split[0], "WE", 3) || \
	!ft_strncmp(split[0], "NO", 3) || !ft_strncmp(split[0], "SO", 3))
		if (ft_strncmp(ft_strrchr(split[1], '.'), XPM, 5))
		{
		put_error(S_XPM, string);
		free_split(split);
		free_split(cub->file);
		exit(1);
		}
}

static void parse_strings(t_state *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		check_string(cub, cub->file[i]);
		i++;
	}
}

void	parsing(int argc, char **argv, t_state *cub)
{
	parse_conf(argc, argv);
	cub->file = ft_get_file(argv[1]);
	init_amount(&cub->data);
	parse_strings(cub);
}
