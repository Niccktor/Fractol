/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:48:59 by nicktor           #+#    #+#             */
/*   Updated: 2019/04/04 22:21:26 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		ft_reve(t_mlx *all)
{
	int				i;
	int				j;
	int				k;
	unsigned int	color;

	i = 0;
	k = all->win->height;
	while (i < all->win->height / 2)
	{
		j = -1;
		while (++j < all->win->width)
		{
			color = all->win->img_str[(i) * all->win->width + j];
			ft_fill_pixel(all, j, k, color);
		}
		i++;
		k--;
	}
}

void			ft_mandelbrot(t_mlx *all)
{
	int			x;
	int			y;
	int			i;
	t_complex	z;
	t_complex	c;

	y = -1;
	while ((++y < all->win->height / 2 + 1 && all->fra->reve == 1)
			|| (y < all->win->height && all->fra->reve == 0))
	{
		x = -1;
		while (++x < all->win->width)
		{
			z = ft_new_complex(0.0, 0.0);
			c = ft_new_complex(x / all->fra->zoom_x + all->fra->x_min,
					y / all->fra->zoom_y + all->fra->y_min);
			i = -1;
			while (++i <= all->fra->iter && ft_complex_mod(z) <= 2.0)
				ft_complex_calc(&z, c);
			ft_fill_pixel(all, x, y, ft_get_color(all, i));
		}
	}
	if (all->fra->reve == 1)
		ft_reve(all);
}
