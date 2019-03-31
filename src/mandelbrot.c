/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:48:59 by nicktor           #+#    #+#             */
/*   Updated: 2019/03/31 01:59:33 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>
#include <stdio.h>

t_complex	ft_new_complex(double re, double ir)
{
	t_complex z;

	z.re = re;
	z.ir = ir;
	return (z);
}

void		ft_complex_calc(t_complex *z, t_complex c)
{
	double tmp;

	tmp = z->re;
	z->re = z->re * z->re - z->ir * z->ir + c.re;
	z->ir = 2 * z->ir * tmp + c.ir;
}

double		ft_complex_mod(t_complex z)
{
	return (z.re * z.re + z.ir * z.ir);
}

void		ft_mandelbrot(t_mlx *all)
{
	int 		x;
	int		y;
	int		i;
	double		tmp;
	t_complex	z;
	t_complex	c;
	
	y = 0;	
	while (y < all->win->height)
	{
		x = 0;
		while (x < all->win->width)
		{
			z = ft_new_complex(0.0, 0.0);
			c = ft_new_complex(-2.2 + (double)x * 4.4 / (double)all->win->width
				, 2.2 - (double)y * 4.4 / (double)all->win->height);
			i = 0;
// uncom si rebug	while ((i <= all->cam->iter)
//				&& !(ft_complex_mod(z) > 4.0))
			while ((i <= all->cam->iter) && ft_complex_mod(z) < 4.0)
			{
				ft_complex_calc(&z, c);
				i++;
			}
			ft_fill_pixel(all, x, y, ft_get_color(all, i));
			x++;
		}
		y++;
	}
}
