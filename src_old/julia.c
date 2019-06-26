/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/05/06 14:44:57 by tbeguin          ###   ########.fr       */
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

static void		ft_calcul(t_mlx *all, t_complex z, t_complex c, t_point pos)
{
	int i;

	i = -1;
	while (++i <= all->fra->iter && ft_complex_mod(z) <= 2.0)
		ft_complex_calc(&z, c);
	ft_fill_pixel(all, pos.x, pos.y, ft_get_color(all, i));
}

int				ft_julia(t_mlx *all, int x_mouse, int y_mouse)
{
	t_point		pos;
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
		ft_reve(all);
	return (0);
}
