/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/26 07:58:44 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <pthread.h>

/*
**					Key 
*/
# define R 15
# define ONE 18
# define TOW 19
# define THREE 20
# define FOUR 21
# define FIVE 22
# define SIX 23
# define SEVEN 24
# define EIGHT 25
# define O 31
# define P 35
# define L 37
# define K 40
# define ESC 53
# define MORE_PAD 69
# define LESS_PAD 78
# define ONE_PAD 83
# define TOW_PAD 84
# define THREE_PAD 85
# define FOUR_PAD 86
# define SIX_PAD 88
# define SEVEN_PAD 89
# define EIGHT_PAD 91
# define NINE_PAD 92
# define PAGE_UP 116
# define PAGE_DOWN 121
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

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
double				ft_complex_mod(t_complex z);
t_point				ft_new_point(int x, int y);
double				power(double a, int pow);
/*
**					Mandelbrot.c
*/
void				*mandelbrot(void *threads);
void				init_mandelbrot(t_mlx *all);
/*
**					julia.c
*/
void				*julia(void *threads);
void				init_julia(t_mlx *all);
void				init_julia_preset(t_mlx *all, int i);
/*
**					ship.c
*/
void				*ship(void *threads);
void				init_ship(t_mlx *all);

void				threads(t_mlx all);
#endif
