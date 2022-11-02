/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:00 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 03:56:26 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# define RES_X	1000
# define RES_Y	1000

typedef struct s_amount
{
	int	n_no;
	int	n_so;
	int	n_we;
	int	n_ea;
	int	n_f;
	int	n_c;
}	t_amount;

typedef struct s_state
{
	void		*mlx;
	void		*win;
	char		**file;
	char		**info[6];
	t_amount	data;
	char		**map;
	char		*c_ea;
	char		*c_we;
	char		*c_no;
	char		*c_so;
	int			floor[3];
	int			ceiling[3];
}	t_state;

void	init_amount(t_amount *data);

#endif
