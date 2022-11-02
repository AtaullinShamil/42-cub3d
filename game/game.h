/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:53:56 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 19:25:59 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

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

int		game(int key, t_state *cub);
void	render(t_state *cub);

int	esc(t_state *cub);

#endif
