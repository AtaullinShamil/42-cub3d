/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:50 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/26 21:03:26 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "stdio.h"

static void	parse_conf(int argc, char **argv)
{
	int	fd;
	if (argc == 1)
		put_error(CF_N, NULL);
	if (argc > 2)
		put_error(CF_TMA, NULL);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), CUB, 5))
		put_error(CF_CUB, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		put_error(F_N, argv[1]);
	close(fd);
}



void	parsing(int argc, char **argv)
{
	char	**file;
	int i = 0;

	parse_conf(argc, argv);
	file = ft_get_file(argv[1]);
}
