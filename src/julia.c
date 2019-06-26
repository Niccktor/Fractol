/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/26 02:52:16 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>
/*
static void		ft_calcul(t_mlx *all, t_complex z, t_complex c, t_point pos)
{
	int i;

	i = -1;
	while (++i <= all->fra->iter && ft_complex_mod(z) <= 2.0)
		ft_complex_calc(&z, c);
	ft_fill_pixel(all, pos.x, pos.y, ft_get_color(all, i));
}
*/
void			*julia(t_mlx *all)
{
/*	t_point		pos;
	t_complex	z;
	t_complex	c;

	pos.y = -1;
	if (!(y_mouse >= 0 && y_mouse <= all->win->height
			&& x_mouse >= 0 && x_mouse <= all->win->width))
		return (-1);
	while ((++(pos.y) < all->win->height / 2 + 1 && all->fra->reve == 1)
			|| (pos.y < all->win->height && all->fra->reve == 0))
	{
		pos.x = -1;
		while (++(pos.x) < all->win->width)
		{
			z = ft_new_complex(pos.x / all->fra->zoom_x + all->fra->x_min,
					pos.y / all->fra->zoom_y + all->fra->y_min);
			c = ft_new_complex(x_mouse / all->fra->zoom_x + all->fra->x_min,
					y_mouse / all->fra->zoom_y + all->fra->y_min);
			ft_calcul(all, z, c, pos);
		}
	}
	if (all->fra->reve == 1)
		ft_reve(all);*/
	all->fra.x_min = -2.2;
	return (0);
}

void		init_julia(t_mlx *all)
{
	all->fra.fractal = julia;
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
