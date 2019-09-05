/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:48:59 by nicktor           #+#    #+#             */
/*   Updated: 2019/09/05 12:06:32 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

static void		ft_mandelbrot_calc(t_thread *thd, t_point point,
					t_complex z, t_complex c)
{
	int			i;
	double		tmp;

	i = -1;
	while (++i <= thd->all.fra.iter && ft_complex_mod(z) <= 2.0)
	{
		if (thd->all.fra.pow == 3)
		{
			tmp = power(z.re, 3) - 3 * z.re * power(z.ir, 2) + c.re;
			z.ir = 3 * power(z.re, 2) * z.ir - power(z.ir, 3) + c.ir;
			z.re = tmp;
		}
		else
		{
			tmp = power(z.re * z.re + z.ir * z.ir, thd->all.fra.pow / 2) *
				cos(thd->all.fra.pow * atan2(z.ir, z.re)) + c.re;
			z.ir = power(z.re * z.re + z.ir * z.ir, thd->all.fra.pow / 2) *
				sin(thd->all.fra.pow * atan2(z.ir, z.re)) + c.ir;
			z.re = tmp;
		}
	}
	ft_fill_pixel(&thd->all, point.x, point.y, ft_get_color(&thd->all, i));
}

void			*mandelbrot(void *thread)
{
	t_thread	*thd;
	t_point		point;
	t_complex	z;
	t_complex	c;
	int			x_max;

	thd = (t_thread *)thread;
	point = ft_new_point(0, 0);
	x_max = (thd->i + 1) * (thd->all.win.width / thd->all.cam.threads);
	while (point.y < thd->all.win.height)
	{
		point.x = thd->i * (thd->all.win.width / thd->all.cam.threads);
		while (point.x < x_max)
		{
			z = ft_new_complex(0.0, 0.0);
			c = ft_new_complex(point.x / thd->all.fra.zoom_x
					+ thd->all.fra.x_min, point.y / thd->all.fra.zoom_y
					+ thd->all.fra.y_min);
			ft_mandelbrot_calc(thd, point, z, c);
			point.x++;
		}
		point.y++;
	}
	return (0);
}

void			init_mandelbrot(t_mlx *all)
{
	all->fra.fractal = mandelbrot;
	all->fra.x_min = -2.2;
	all->fra.x_max = 2.2;
	all->fra.y_min = -2.2;
	all->fra.y_max = 2.2;
	all->fra.zoom_x = all->win.width / (all->fra.x_max - all->fra.x_min);
	all->fra.zoom_y = all->win.height / (all->fra.y_max - all->fra.y_min);
	all->fra.pow = 2;
	all->fra.iter = 100;
	all->fra.lock = 1;
	init_cam(&all->cam);
}
