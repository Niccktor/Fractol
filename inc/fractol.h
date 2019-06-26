/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/26 04:35:19 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <pthread.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_complex
{
	double			re;
	double			ir;
}					t_complex;

typedef struct		s_win
{
	void			*win_ptr;
	char			*name;
	int				width;
	int				height;
	void			*img_ptr;
	unsigned int	*img_str;
}					t_win;

typedef struct		s_cam
{
	int				mouse_left;
	int				mouse_right;
	int				x_mouse;
	int				y_mouse;
	unsigned int	color;
	int				o;
	int				r;
	int				g;
	int				b;
	unsigned int	color_end;
	int				threads; 
}					t_cam;

typedef struct		s_fract
{
	void			*(*fractal)();
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	double			zoom_x;
	double			zoom_y;
	int				iter;
	int				pow;
}					t_fract;

typedef struct		s_mlx
{
	void				*mlx_ptr;
	char				*name;
	struct s_win			win;
	struct s_cam			cam;
	struct s_fract			fra;
}					t_mlx;

typedef struct		s_thread
{
	int				i;
	t_mlx			all;
	pthread_t		thread;
}					t_thread;
/*
**					main.c
*/
int					argv_err(t_mlx *all);
int					ft_exit(t_mlx *all);
/*
**					init.c
*/
void				init_all(t_mlx *all, char *argv);
void				init_cam(t_cam *all);
void				init_win(t_mlx *all);
/*
**					key_event.c
*/
int					ft_key_press(int key, t_mlx *all);
/*
**					mouse_event.c
*/
void				ft_zoom_in(t_mlx *all, int x, int y, double zoom);
void				ft_zoom_out(t_mlx *all, int x, int y, double zoom);
int					ft_mouse_press(int key, int x, int y, t_mlx *param);
int					ft_mouse_release(int key, int x, int y, t_mlx *param);
int					ft_mouse_move(int x, int y, t_mlx *param);
t_complex			ft_new_complex(double re, double ir);
/*
**					util.c
*/
t_mlx				*ft_new_mlx();
t_mlx				*ft_new_win(t_mlx *mlx_all, char *s, int width, int height);
t_mlx				*ft_new_cam(t_mlx *all, char *argv);
t_mlx				*ft_new_fract(t_mlx *all);
/*
**					draw.c
*/
void				ft_fill_pixel(t_mlx *all, int x, int y, unsigned int color);
void				show_img(t_mlx *all);
void				ft_legend(t_mlx *all);
/*
**					color.c
*/
unsigned int		ft_get_color(t_mlx *all, int i);
/*
**					math.c
*/
t_complex			ft_new_complex(double re, double ir);
void				ft_complex_calc(t_complex *z, t_complex c);
double				ft_complex_mod(t_complex z);
t_point				ft_new_point(int x, int y);
/*
**					Mandelbrot.c
*/
void				*mandelbrot(void *threads);
void				init_mandelbrot(t_mlx *all);
/*
**					julia.c
*/
void				*julia(t_mlx *all);
void				init_julia(t_mlx *all);
/*
**					ship.c
*/
void				*ship(t_mlx *all);
void				init_ship(t_mlx *all);

void				threads(t_mlx all);
#endif
