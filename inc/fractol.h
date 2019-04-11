/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/11 18:00:05 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <pthread.h>

typedef struct		s_complex
{
	double			re;
	double			ir;
}					t_complex;

typedef struct		s_win
{
	void			*win_ptr;
	char			*name;
	int 			width;
	int				height;
	void			*img_ptr;
	unsigned int	*img_str;
}					t_win;

typedef struct		s_cam
{
	char 			fractal;
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
}					t_cam;

typedef struct		s_fract
{
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	double			zoom_x;
	double			zoom_y;
	int				iter;
	int				reve;
}					t_fract;
/*
typedef struct		s_thread
{
	pthread_t		**thread;
	int				wait;
	int				exit;
	int				nb;
}					t_thread;
*/
typedef struct		s_mlx
{
	void			*mlx_ptr;
	t_win			*win;
	t_cam			*cam;
	t_fract			*fra;
/*	t_thread		*thread;*/
}					t_mlx;

/*
**					main.c
*/

int		ft_close(char *e);

/*
 *					key_event.c
 */
int		ft_key_hook(int key, void *para);

/*
**					mouse_event.c
*/

void		ft_zoom_in(t_mlx *all, int x, int y);
void		ft_zoom_out(t_mlx *all, int x, int y);

int			ft_mouse_press(int key, int x, int y, void *param);
int			ft_mouse_release(int key, int x, int y, void *param);
int			ft_mouse_move(int x, int y, void *param);

void		ft_mandelbrot(t_mlx *all);
t_complex	ft_new_complex(double re, double ir);

/*
 *					util.c
 */
t_mlx	*ft_new_mlx();
t_mlx	*ft_new_win(t_mlx *mlx_all, char *s, int width, int height);
t_mlx	*ft_new_cam(t_mlx *all);
t_mlx	*ft_new_fract(t_mlx *all);
t_mlx	*ft_new_thread(t_mlx *all);
/*
**					draw.c
*/

void		ft_fill_pixel(t_mlx *all, int x, int y, unsigned int color);
void		ft_render(t_mlx *all);
void		ft_legend(t_mlx *all);
/*
**					color.c
*/

unsigned int	ft_get_color(t_mlx *all, int i);

/*
**					math.c
*/

t_complex	ft_new_complex(double re, double ir);
void		ft_complex_calc(t_complex *z, t_complex c);
double		ft_complex_mod(t_complex z);

/*
**					julia.c
*/

int		ft_julia(t_mlx *all, int x_mouse, int y_mouse);
/*
**					ship.c
*/
void	ft_ship(t_mlx *all);
#endif
