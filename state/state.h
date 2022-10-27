/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:00 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/27 20:48:53 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef struct s_amount
{
	int	NO;
	int	SO;
	int	WE;
	int	EA;
	int F;
	int C;
}	t_amount;

typedef struct s_malloc
{
	char	**str_1[6];
	char	**str_2[2];
}	t_malloc;


typedef struct s_state
{
	char		**file;
	t_amount	data;
	t_malloc	mal;
}	t_state;

void	init_amount(t_amount *data);

#endif
