/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:00 by ntojamur          #+#    #+#             */
/*   Updated: 2022/10/28 05:43:25 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef struct s_amount
{
	int	n_no;
	int	n_so;
	int	n_we;
	int	n_ea;
	int	n_f;
	int	n_c;
}	t_amount;

typedef struct s_malloc
{
	char	**info[6];
}	t_malloc;

typedef struct s_state
{
	char		**file;
	t_amount	data;
	t_malloc	mem;
}	t_state;

void	init_amount(t_amount *data);

#endif
