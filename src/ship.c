/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:13:56 by tbeguin           #+#    #+#             */
/*   Updated: 2019/09/05 11:04:14 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		ship_calc(t_thread *thd, t_point point
					, t_complex z, t_complex c)
{
	int			i;
	double		tmp;
	double		tmp2;

	i = -1;
	while (++i < thd->all.fra.iter && ft_complex_mod(z) <= 2.0)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.ir * z.ir + c.re;
		tmp2 = z.ir * tmp;
		z.ir = (tmp2 < 0) ? 2 * (tmp2 * -1) + c.ir : 2 * tmp2 + c.ir;
	}
	ft_fill_pixel(&thd->all, point.x, point.y, ft_get_color(&thd->all, i));
}

void			*ship(void *threads)
{
	t_thread	*thd;
	t_point		point;
	t_complex	z;
	t_complex	c;
	int			x_max;

	thd = (t_thread *)threads;
	point = ft_new_point(0, 0);
	x_max = (thd->i + 1) * (thd->all.win.width / thd->all.cam.threads);
	while (point.y < thd->all.win.height)
	{
		point.x = thd->i * (thd->all.win.width / thd->all.cam.threads);
		while (point.x < x_max)
		{
			z = ft_new_complex(0.0, 0.0);
			c = ft_new_complex(point.x / thd->all.fra.zoom_x
					+ thd->all.fra.x_min
					, point.y / thd->all.fra.zoom_y + thd->all.fra.y_min);
			ship_calc(thd, point, z, c);
			point.x++;
		}
		point.y++;
	}
	return (0);
}

void			init_ship(t_mlx *all)
{
	all->fra.fractal = ship;
	all->fra.x_min = -2.2;
	all->fra.x_max = 2.2;
	all->fra.y_min = -2.2;
	all->fra.y_max = 2.2;
	all->fra.iter = 100;
	all->fra.pow = 2;
	all->fra.zoom_x = all->win.width / (all->fra.x_max - all->fra.x_min);
	all->fra.zoom_y = all->win.width / (all->fra.y_max - all->fra.y_min);
	all->fra.lock = 1;
	init_cam(&all->cam);
}
