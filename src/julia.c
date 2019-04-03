/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/03 21:15:07 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>

static void	ft_reve(t_mlx *all)
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
	while (++y < all->win->height / 2 + 1 )
	{
		x = -1;
		while (++x < all->win->width)
		{
			z = ft_new_complex(all->cam->x_min + x
					* all->cam->x_max / all->win->width
					, all->cam->y_min - y * all->cam->y_max / all->win->height);
			c = ft_new_complex(all->cam->x_min + x_mouse
					* all->cam->x_max / all->win->width
					, all->cam->y_min - y_mouse
					* all->cam->y_max / all->win->height);
			i = -1;
			while (++i <= all->cam->iter && ft_complex_mod(z) <= 2.0)
				ft_complex_calc(&z, c);
			ft_fill_pixel(all, x, y, ft_get_color(all, i));
		}
	}
	ft_reve(all);
	return (0);
}
