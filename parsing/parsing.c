/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:50 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 23:04:29 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

static void	init_map(t_state *map)
{
	map->map.n = 0;
	map->map.s = 0;
	map->map.e = 0;
	map->map.w = 0;
}

static void	check_texture_path(t_state *cub)
{
	int	fd;

	fd = open(cub->sprites.c_no, O_RDONLY);
	if (fd == -1)
		put_error_exit(cub->sprites.c_no, ERR_XPM);
	close(fd);
	fd = open(cub->sprites.c_so, O_RDONLY);
	if (fd == -1)
		put_error_exit(cub->sprites.c_so, ERR_XPM);
	close(fd);
	fd = open(cub->sprites.c_ea, O_RDONLY);
	if (fd == -1)
		put_error_exit(cub->sprites.c_ea, ERR_XPM);
	close(fd);
	fd = open(cub->sprites.c_we, O_RDONLY);
	if (fd == -1)
		put_error_exit(cub->sprites.c_we, ERR_XPM);
	close(fd);
}

void	parsing(int argc, char **argv, t_state *cub)
{
	parse_conf(argc, argv);
	cub->file = ft_get_file(argv[1]);
	parse_strings(cub);
	parse_repeats(cub);
	init_arg(cub);
	check_texture_path(cub);
	cub->map.map = &cub->file[6];
	parse_map(cub->map.map);
	init_map(cub);
}
