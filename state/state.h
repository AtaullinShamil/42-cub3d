/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:00 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 16:09:29 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# define RES_X	720	////
# define RES_Y	480	////

typedef struct s_amount
{
	int	n_no;
	int	n_so;
	int	n_we;
	int	n_ea;
	int	n_f;
	int	n_c;
}	t_amount;

typedef struct s_img_info	////
{							////
	void	*img;			////
	int		*adr;			////
	int		x;				////
	int		y;				////
	int		endian;			////
}	t_img_info;				////

typedef struct s_img		////
{							////
	t_img_info	no;			////
	t_img_info	we;			////
	t_img_info	so;			////
	t_img_info	ea;			////
	void	*img_ptr;		////
	int		*data_addr;		////
	int			bpp;		////
	int			size_line;	////
	int			endian;		////
}	t_img;					////


typedef struct s_state
{
	void		*mlx;
	void		*win;
	t_img		img;			////
	char		**file;
	char		**info[6];
	t_amount	data;
	char		**map;
	char		*c_ea;
	char		*c_we;
	char		*c_no;
	char		*c_so;
	int			floor;
	int			ceiling;
}	t_state;

void	init_amount(t_amount *data);

#endif
