/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/09/05 12:04:56 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

static void		julia_calc(t_thread *thd, t_point point,
					t_complex z, t_complex c)
{
	int		i;
	double	tmp;

	i = -1;
	while (++i <= thd->all.fra.iter && ft_complex_mod(z) <= 2.0)
	{
		tmp = power(z.re * z.re + z.ir * z.ir, thd->all.fra.pow / 2) *
			cos(thd->all.fra.pow * atan2(z.ir, z.re)) + c.re;
		z.ir = power(z.re * z.re + z.ir * z.ir, thd->all.fra.pow / 2) *
			sin(thd->all.fra.pow * atan2(z.ir, z.re)) + c.ir;
		z.re = tmp;
	}
	ft_fill_pixel(&thd->all, point.x, point.y, ft_get_color(&thd->all, i));
}

void			*julia(void *thread)
{
	t_thread	*thd;
	t_point		point;
	t_complex	z;
	int			x_max;

	thd = (t_thread *)thread;
	point = ft_new_point(-1, -1);
	x_max = (thd->i + 1) * (thd->all.win.width / thd->all.cam.threads);
	while (++(point.y) < thd->all.win.height)
	{
		point.x = thd->i * (thd->all.win.width / thd->all.cam.threads);
		while (++(point.x) <= x_max)
		{
			z = ft_new_complex(point.x / thd->all.fra.zoom_x
					+ thd->all.fra.x_min
					, point.y / thd->all.fra.zoom_y + thd->all.fra.y_min);
			julia_calc(thd, point, z, thd->all.fra.c);
		}
	}
	return (0);
}

void			init_julia(t_mlx *all)
{
	all->fra.fractal = julia;
	all->fra.x_min = -2.2;
	all->fra.x_max = 2.2;
	all->fra.y_min = -2.2;
	all->fra.y_max = 2.2;
	all->fra.iter = 100;
	all->fra.pow = 2;
	all->fra.lock = 0;
	all->fra.zoom_x = all->win.width / (all->fra.x_max - all->fra.x_min);
	all->fra.zoom_y = all->win.height / (all->fra.y_max - all->fra.y_min);
	all->fra.c = ft_new_complex(0 / all->fra.zoom_x
		+ all->fra.x_min
		, 0 / all->fra.zoom_y
		+ all->fra.y_min);
	init_cam(&all->cam);
}

void			init_julia_preset(t_mlx *all, int i)
{
	t_complex	c;

	init_julia(all);
	all->fra.lock = 1;
	if (i == 1)
		c = ft_new_complex(0.3, 0.5);
	else if (i == 2)
		c = ft_new_complex(0.285, 0.01);
	else if (i == 3)
		c = ft_new_complex(-0.038088, 0.9754633);
	else if (i == 4)
		c = ft_new_complex(-1.476, 0);
	else if (i == 5)
		c = ft_new_complex(-0.8, 0.156);
	else
		c = ft_new_complex(0, 0);
	ft_putnbr(i);
	ft_putstr("\n");
	all->fra.c = c;
}
