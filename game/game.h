/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:53:56 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 19:26:19 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "math.h"

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

int		game(int key, t_state *cub);
void	render(t_state *cub);
void	draw_textures(t_state *data, int i);
void	draw_func_helper(t_state *data);
void	dda_algoritm(t_state	*data);

void	move_w(t_state	*data);
void	move_a(t_state	*data);
void	move_s(t_state	*data);
void	move_d(t_state	*data);
int		mouse_hook(int x, int y, t_state *data);

int		esc(t_state *cub);

#endif
