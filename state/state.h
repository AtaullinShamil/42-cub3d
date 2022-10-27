/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:00 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/27 17:02:34 by ntojamur         ###   ########.fr       */
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


typedef struct s_state
{
	char		**file;
	t_amount	data;
}	t_state;

void	init_amount(t_amount *data);

#endif
