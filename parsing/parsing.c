/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:50 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/30 18:42:59 by ntojamur         ###   ########.fr       */
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

void	parsing(int argc, char **argv, t_state *cub)
{
	parse_conf(argc, argv);
	cub->file = ft_get_file(argv[1]);
	parse_strings(cub);
	parse_repeats(cub);
	init_arg(cub);
	cub->map = &cub->file[6];
	parse_map(cub->map);
}
