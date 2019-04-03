/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/03 19:35:29 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>


int		ft_julia(t_mlx *all, int x_mouse, int y_mouse)
{
	int			i;
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;

	y = -1;
	if (!(y_mouse >= 0 && y_mouse <= all->win->height
			&& x_mouse >= 0 && x_mouse <= all->win->width))
		return (-1);
	while (++y < all->win->height)
	{
		x = -1;
		while (++x < all->win->width)
		{
			z = ft_new_complex(-2.2 + x * 4.4 / all->win->width
					, 2.2 - y * 4.4 / all->win->height);
			c = ft_new_complex(-2.2 + x_mouse * 4.4 /
					all->win->width
					, 2.2 - y_mouse * 4.4 / all->win->height);
			i = -1;
			while (++i <= all->cam->iter && ft_complex_mod(z) <= 2.0)
				ft_complex_calc(&z, c);
			ft_fill_pixel(all, x, y, ft_get_color(all, i));
		}
	}
	return (0);
}
