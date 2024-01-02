/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:14:15 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/27 11:18:02 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <mlx.h>
# include <math.h>
# include <stdint.h>

# define WIDTH 1400
# define HEIGHT 600
# define TEX_WIDTH 80
# define TEX_HEIGHT 80

typedef struct s_index
{
	int	x;
	int	y;
}	t_index;

typedef struct s_img
{
	void	*reference;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}	t_img;

typedef struct s_window
{
	t_map	*map;
	t_img	image[4];
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_window;

void	ft_raycasting(t_map *map, t_window *window);
void	dda_algo(t_map *map);
double	get_delta_dist_x(t_map *map);
double	get_delta_dist_y(t_map *map);
double	get_side_dist_x(t_map *map, double delta_dist_x);
double	get_side_dist_y(t_map *map, double delta_dist_y);
bool	compute_perp_wall_dist(t_map *map);
void	paint_vertical_stripe(t_map *map, t_img *image,
			int x, t_img *texture);
int		get_tex_x_coordinate(t_map *map);
int		get_tex_y_coordinate(t_map *map, double step);
int		get_draw_start(int line_height);
int		get_draw_end(int line_height);
void	launch_graphic_env(t_map *map);
void	ft_mlx_error(t_map *map, t_window *window, char *str);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_pixel_color(t_img *texture, int x, int y);
int		ft_handle_input(int keycode, t_window *window);
bool	is_walkable(char c);
void	move_backward(t_window *window);
void	move_forward(t_window *window);
void	rotate_left(t_window *window);
void	rotate_right(t_window *window);
int		ft_close(int keycode, t_window *window);
int		ft_rotate(int keycode, t_window *window);
void	strafe_right(t_window *window);
void	strafe_left(t_window *window);

#endif
