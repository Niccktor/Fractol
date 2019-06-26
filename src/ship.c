/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:13:56 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/26 02:52:42 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
/*
static void	ft_ship_calc(t_complex *z, t_complex c)
{
	double tmp;
	double tmp2;

	tmp = z->re;
	z->re = z->re * z->re - z->ir * z->ir + c.re;
	tmp2 = z->ir * tmp;
	z->ir = (tmp2 < 0) ? 2 * (tmp2 * -1) + c.ir : 2 * tmp2 + c.ir;
}
*/
void		*ship(t_mlx *all)
{/*
	int			x;
	int			y;
	int			i;
	t_complex	z;
	t_complex	c;

	y = -1;
	while (++y < all->win->height)
	{
		x = -1;
		while (++x < all->win->width)
		{
			z = ft_new_complex(0.0, 0.0);
			c = ft_new_complex(x / all->fra->zoom_x + all->fra->x_min,
					y / all->fra->zoom_y + all->fra->y_min);
			i = -1;
			while (++i < all->fra->iter && ft_complex_mod(z) <= 2.0)
				ft_ship_calc(&z, c);
			ft_fill_pixel(all, x, y, ft_get_color(all, i));
		}
	}*/
	all->fra.x_min = -2.2;
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
	init_cam(&all->cam);
}
