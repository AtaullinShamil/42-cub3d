/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:00 by ntojamur          #+#    #+#             */
/*   Updated: 2022/11/06 17:41:48 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "../mlx/mlx.h"

# define RES_X	1000	////
# define RES_Y	1000	////

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

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		mouse_x;
	int		map_flag;
}	t_player;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_raycast;

typedef struct s_wall
{
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
}	t_wall;

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
	int		**i_map;
	int		n;
	int		s;
	int		e;
	int		w;
}	t_map;

typedef struct s_state
{
	void		*mlx;
	void		*win;
	t_img		img;			////
	char		**file;
	char		**info[6];
	t_amount	data;
	//char		**map;
	t_map		map;
	t_char_img	sprites;
	int			floor;
	int			ceiling;
	t_player	player;
	t_raycast	ray;
	t_wall		wall;
}	t_state;

void	init_amount(t_amount *data);
void	set_all_textures(t_state *cub);

#endif
