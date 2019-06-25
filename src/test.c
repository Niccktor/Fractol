/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/19 17:34:25 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>
/*
static void		ft_calcul(t_mlx *all, t_complex z, t_complex c)
{
	int i;

	i = -1;
	while (++i <= all->fra->iter && ft_complex_mod(z) <= 2.0)
		ft_complex_calc(&z, c);
	ft_fill_pixel(all, pos.x, pos.y, ft_get_color(all, i));
}
*/
void		*test(void *thread)
{
	t_thread	*thd;
	t_point		pos;
	int			x_max;
	t_complex	c;
	t_complex	z;
	int			i;

	thd = (t_thread *)thread;
	pos.y = -1;
	while (++(pos.y) < thd->data->win->height)
	{
		pos.x = thd->i * (thd->data->win->width / 16);
		x_max = (thd->i + 1) * (thd->data->win->width / 16);
		while (pos.x < x_max)
		{
			pos.x++;
			z = ft_new_complex(0.0, 0.0);
			c = ft_new_complex(pos.x / thd->data->fra->zoom_x + thd->data->fra->x_min,
					pos.y / thd->data->fra->zoom_y + thd->data->fra->y_min);
			i = -1;
			while (++i <= thd->data->fra->iter && ft_complex_mod(z) <= 2.0)
				ft_complex_calc(&z, c);
			ft_fill_pixel(thd->data, pos.x, pos.y, ft_get_color(thd->data, i));
		}
	}
	return (thread);
}

void		threads(t_mlx *all)
{
	int			i;
	t_thread	threads[16];

	i = 0;
	while (i < 16)
	{
		threads[i].i = i;
		threads[i].data = all;
		pthread_create(&threads[i].thread, NULL, test, &threads[i]);
		i++;
	}
	i = 0;
	while (i < 16)
		pthread_join(threads[i++].thread, NULL);
}
