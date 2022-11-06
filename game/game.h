/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:53:56 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/05 00:02:39 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "math.h"
# include "stdio.h"

# include "../mlx/mlx.h"
# include "../state/state.h"
# include "../parsing/parsing.h"

# define ESC		53
# define W_KEY		13
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define RIGHT_KEY	124
# define LEFT_KEY	123

# define T_SIZE 64
# define MS 0.25
# define RS 0.20

void	init_player(t_state *cub);
int		game(int key, t_state *cub);
void	render(t_state *cub);

int	esc(t_state *cub);

#endif
