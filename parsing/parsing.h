/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:37:44 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/30 17:04:36 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include "../error/error.h"
# include "../state/state.h"

# define CUB	".cub"
# define XPM	".xpm"

void	parsing(int argc, char **argv, t_state *cub);
char	**ft_get_file(char *file);
void	parse_strings(t_state *cub);
int		check_rgb(char **split, char *string);
void	parse_repeats(t_state *cub);
void	init_arg(t_state *cub);

int		split_size(char **split);
void	free_split(char **split);
void	free_all(t_state *cub);

#endif
