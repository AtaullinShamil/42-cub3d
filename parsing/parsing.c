/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:39:50 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/26 19:37:18 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(int argc, char **argv)
{
	if (argc == 1)
		put_error(CF_N, NULL);
	if (argc > 2)
		put_error(CF_TMA, NULL);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), CUB, 5))
		put_error(CF_CUB, argv[1]);
	if (open(argv[1], O_RDONLY) == -1)
		put_error(F_N, argv[1]);
}
