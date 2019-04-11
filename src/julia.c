/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/11 17:44:08 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>

static void		ft_reve(t_mlx *all)
{
	unsigned int	color;
	int				i;
	int				j;
	int				k;
	int				l;

	i = -1;
	k = all->win->height;
	while (++i < all->win->height / 2)
	{
		l = all->win->width;
		j = -1;
		while (++j < all->win->width)
		{
			color = all->win->img_str[i * all->win->width + j];
			ft_fill_pixel(all, l, k, color);
			l--;
		}
		k--;
	}
}

static void		ft_calcul(t_mlx *all,t_complex z, t_complex c, int x, int y)
{
	int i;

	i = -1;
	while (++i <= all->fra->iter && ft_complex_mod(z) <= 2.0)
		ft_complex_calc(&z, c);
	ft_fill_pixel(all, x, y, ft_get_color(all, i));
}

int				ft_julia(t_mlx *all, int x_mouse, int y_mouse)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;

	y = -1;
	if (!(y_mouse >= 0 && y_mouse <= all->win->height
			&& x_mouse >= 0 && x_mouse <= all->win->width))
		return (-1);
	while ((++y < all->win->height / 2 + 1 && all->fra->reve == 1)
			|| (y < all->win->height && all->fra->reve == 0))
	{
		x = -1;
		while (++x < all->win->width)
		{
			z = ft_new_complex(x / all->fra->zoom_x + all->fra->x_min,
					y / all->fra->zoom_y + all->fra->y_min);
			c = ft_new_complex(x_mouse / all->fra->zoom_x + all->fra->x_min,
					y_mouse / all->fra->zoom_y + all->fra->y_min);
		/*	printf("\nz->re = %f, z->ir %f\nc->re = %f, c->ir %f", z.re, z.ir, c.re, c.ir);*/
			ft_calcul(all, z, c, x ,y);
		}
	}
	if (all->fra->reve == 1)
		ft_reve(all);
	return (0);
}
