/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:43:16 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/28 19:44:44 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int	check_rgb(char **split, char *string)
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
