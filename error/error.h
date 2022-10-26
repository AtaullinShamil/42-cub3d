/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:42:14 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/26 19:37:37 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include "../libft/libft.h"

#define CF_N	"there is no configuration file"
#define CF_TMA	"too many arguments"
#define CF_CUB	"the configuration file have to be .cub : "
#define F_N		"there is no the file in the directory : "

void	put_error(char *str, char *src);

#endif
