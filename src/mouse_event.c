/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:22:14 by tbeguin           #+#    #+#             */
/*   Updated: 2019/09/05 11:23:36 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_zoom_in(t_mlx *all, int x, int y, double zoom)
{
	double	e;
	double	x1;

	if (all->fra.lock == 1)
	{
		e = (all->fra.x_max - all->fra.x_min) / 2;
		x1 = x / all->fra.zoom_x + all->fra.x_min;
		all->fra.x_min = x1 - e * zoom;
		all->fra.x_max = x1 + e * zoom;
		e = (all->fra.y_max - all->fra.y_min) / 2;
		x1 = y / all->fra.zoom_y + all->fra.y_min;
		all->fra.y_min = x1 - e * zoom;
		all->fra.y_max = x1 + e * zoom;
		all->fra.zoom_x = all->win.width
			/ (all->fra.x_max - all->fra.x_min);
		all->fra.zoom_y = all->win.height
			/ (all->fra.y_max - all->fra.y_min);
	}
}

void	ft_zoom_out(t_mlx *all, int x, int y, double zoom)
{
	double e;
	double x1;

	if (all->fra.lock == 1)
	{
		e = (all->fra.x_max - all->fra.x_min) / 2;
		x1 = x / all->fra.zoom_x + all->fra.x_min;
		all->fra.x_min = x1 - e / zoom;
		all->fra.x_max = x1 + e / zoom;
		e = (all->fra.y_max - all->fra.y_min) / 2;
		x1 = y / all->fra.zoom_y + all->fra.y_min;
		all->fra.y_min = x1 - e / zoom;
		all->fra.y_max = x1 + e / zoom;
		all->fra.zoom_x = all->win.width
			/ (all->fra.x_max - all->fra.x_min);
		all->fra.zoom_y = all->win.height
			/ (all->fra.y_max - all->fra.y_min);
	}
}

int		ft_mouse_press(int key, int x, int y, t_mlx *all)
{
	if (x > all->win.width || x < 0 || y > all->win.height || y < 0)
		return (0);
	if (key == 4)
		ft_zoom_in(all, x, y, 1.2);
	if (key == 5)
		ft_zoom_out(all, x, y, 1.2);
	if (key == 1 && all->fra.fractal == julia)
	{
		if (all->fra.lock == 0)
			all->fra.lock = 1;
		else
			all->fra.lock = 0;
	}
	show_img(all);
	return (0);
}

int		ft_mouse_move(int x, int y, t_mlx *all)
{
	if (x > all->win.width || x < 0 || y > all->win.height || y < 0)
		return (0);
	if (all->fra.fractal == julia && all->fra.lock == 0)
	{
		all->fra.c = ft_new_complex(x / all->fra.zoom_x + all->fra.x_min
				, y / all->fra.zoom_y + all->fra.y_min);
		all->cam.x_mouse = x;
		all->cam.y_mouse = y;
		show_img(all);
	}
	return (0);
}
