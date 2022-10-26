/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:43:31 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/26 18:49:47 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	put_error(char *str, char *src)
{
	ft_putstr_fd("error: cub: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(src, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
