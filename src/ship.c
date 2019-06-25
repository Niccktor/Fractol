/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:13:56 by tbeguin           #+#    #+#             */
/*   Updated: 2019/05/06 14:28:39 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_ship_calc(t_complex *z, t_complex c)
{
	double tmp;
	double tmp2;

	tmp = z->re;
	z->re = z->re * z->re - z->ir * z->ir + c.re;
	tmp2 = z->ir * tmp;
	z->ir = (tmp2 < 0) ? 2 * (tmp2 * -1) + c.ir : 2 * tmp2 + c.ir;
}

void		ft_ship(t_mlx *all)
{
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
	}
}
