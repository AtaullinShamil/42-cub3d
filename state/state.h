/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:00 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/02 18:49:18 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "../mlx/mlx.h"

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

typedef struct s_char_img
{
	char		*c_ea;
	char		*c_we;
	char		*c_no;
	char		*c_so;
}	t_char_img;

typedef struct s_img_info	////
{							////
	void	*img;			////
	int		*adr;			////
	int		bpp;			////
	int		size_line;		////
	int		endian;			////
}	t_img_info;				////

typedef struct s_img		////
{							////
	t_img_info	no;			////
	t_img_info	we;			////
	t_img_info	so;			////
	t_img_info	ea;			////
	t_img_info	window;
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
	t_char_img	sprites;
	int			floor;
	int			ceiling;
}	t_state;

void	init_amount(t_amount *data);
void	set_all_textures(t_state *cub);

#endif
