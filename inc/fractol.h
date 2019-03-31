/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/31 01:50:22 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_complex
{
	double		re;
	double		ir;
}			t_complex;

typedef struct		s_win
{
	void		*win_ptr;
	char		*name;
	int 		width;
	int		height;
	void		*img_ptr;
	unsigned int	*img_str;
}			t_win;

typedef struct		s_cam
{
	unsigned int	color;
	unsigned int	color_end;
	unsigned int	iter;
}			t_cam;

typedef struct		s_mlx
{
	void		*mlx_ptr;
	t_win		*win;
	t_cam		*cam;
}			t_mlx;

/*
**					main.c
*/

void		ft_close(char *e);

/*
 *					event.c
 */
int		ft_key_hook(int key, void *para);
int		ft_mouse_hook(int button, int x, int y, void *para);


void		ft_mandelbrot(t_mlx *all);
t_complex	ft_new_complex(double re, double ir);

/*
 *					util.c
 */
t_mlx	*ft_new_mlx();
t_mlx	*ft_new_win(t_mlx *mlx_all, char *s, int width, int height);
t_mlx	*ft_new_cam(t_mlx *all);
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
#endif
