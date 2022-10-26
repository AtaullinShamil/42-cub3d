/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:43:31 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/26 19:20:07 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	put_error(char *str, char *src)
{
	ft_putstr_fd("error: cub3D: ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (src)
		ft_putstr_fd(src, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
