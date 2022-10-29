/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:50 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/29 04:59:34 by ntojamur         ###   ########.fr       */
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

void	count_quantity(t_state *cub)
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
			cub->c_f = cub->info[i][1];
		else if (ft_strncmp(cub->info[i][0], "C", 2) == 0)
			cub->c_c = cub->info[i][1];
		i++;
	}
}

void	parsing(int argc, char **argv, t_state *cub)
{
	parse_conf(argc, argv);
	cub->file = ft_get_file(argv[1]);
	parse_strings(cub);
	parse_repeats(cub);
	init_arg(cub);
	printf("%s\n",cub->c_c);
	printf("%s\n",cub->c_f);
	printf("%s\n",cub->c_ea);
	printf("%s\n",cub->c_we);
	printf("%s\n",cub->c_no);
	printf("%s\n",cub->c_so);
}
