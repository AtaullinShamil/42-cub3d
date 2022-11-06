/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:42:14 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 19:05:26 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../libft/libft.h"

# define CF_N		"there is no configuration file"
# define CF_TMA		"too many arguments"
# define CF_CUB		"the configuration file have to be .cub : "
# define F_N		"there is no the file in the directory : "
# define S_U		"incorrect parameter name : "
# define S_A		"there is no second part of the argument : "
# define S_XPM		"the file have to be .xpm : "
# define S_D		"there should be three digits : "
# define S_A_D		"arguments must be numbers : "
# define ERR_NUM	"the number must be between 0 and 255 : "
# define ERR_R		"there is a repetition of arguments in the file"
# define ERR_M_S	"invalid character in the string : "
# define ERR_M_C	"there are too many coordinates of start \
					position or there isn't one"
# define ERR_M_W	"the map should be surrounded by walls"
# define ERR_M_A	"map error : the map does not meet the conditions"

void	put_error_exit(char *str, char *src);
void	put_error(char *str, char *src);

#endif
