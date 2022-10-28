/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:50 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/28 18:17:48 by ntojamur         ###   ########.fr       */
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

static int	check_names(char **split, char *string)
{
	if (ft_strncmp(split[0], "EA", 3) && ft_strncmp(split[0], "WE", 3) && \
	ft_strncmp(split[0], "NO", 3) && ft_strncmp(split[0], "SO", 3) && \
	ft_strncmp(split[0], "F", 2) && ft_strncmp(split[0], "C", 2))
	{
		put_error(S_U, string);
		return (1);
	}
	return (0);
}

static int	check_size(char **split, char *string)
{
	if (split_size(split) != 2)
	{
		put_error(S_A, string);
		return (1);
	}
	return (0);
}

static int	check_xpm(char **split, char *string)
{
	if (!ft_strncmp(split[0], "EA", 3) || !ft_strncmp(split[0], "WE", 3) || \
	!ft_strncmp(split[0], "NO", 3) || !ft_strncmp(split[0], "SO", 3))
	{
		if (ft_strncmp(ft_strrchr(split[1], '.'), XPM, 5))
		{
			put_error(S_XPM, string);
			return (1);
		}
	}
	return (0);
}

static int	check_digits(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (ft_isdigit(split[i][j]) != 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_number(char **split_digits)
{
	int	i;
	int	num;

	i = 0;
	while (split_digits[i])
	{
		num = ft_atoi(split_digits[i]);
		if (num > 255)
			return (1);
		i++;
	}
	return (0);
}

static int	check_rgb(char **split, char *string)
{
	char	**split_digits;

	split_digits = ft_split(split[1], ',');
	if (split_size(split_digits) != 3)
	{
		free_split(split_digits);
		put_error(S_D, string);
		return (1);
	}
	if (check_digits(split_digits))
	{
		free_split(split_digits);
		put_error(S_A_D, string);
		return (1);
	}
	if (check_number(split_digits))
	{
		free_split(split_digits);
		put_error(ERR_NUM, string);
		return (1);
	}
	free_split(split_digits);
	return (0);
}

static int	check_string(t_state *cub, char *string, int i)
{
	char	**split;

	cub->info[i] = ft_split(string, ' ');
	split = cub->info[i];
	if (check_names(split, string))
		return (1);
	if (check_size(split, string))
		return (1);
	if (check_xpm(split, string))
		return (1);
	if (!ft_strncmp(split[0], "F", 2) || !ft_strncmp(split[0], "C", 2))
		if (check_rgb(split, string))
			return (1);
	return (0);
}

static void	parse_strings(t_state *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (check_string(cub, cub->file[i], i))
			exit(1);
		i++;
	}
}

void	free_all(t_state *cub)
{
	int	i;

	free_split(cub->file);
	i = 0;
	while (i < 6)
	{
		free_split(cub->info[i]);
		i++;
	}
}

void	parsing(int argc, char **argv, t_state *cub)
{
	parse_conf(argc, argv);
	cub->file = ft_get_file(argv[1]);
	//init_amount(&cub->data);
	parse_strings(cub);
	free_all(cub);
}
