/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:22:14 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/11 17:59:18 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_zoom_in(t_mlx *all, int x, int y)
{
	double	e;
	double	x1;

	if (all->cam->fractal != 'j')
	{
		all->fra->reve = 0;
		e = (all->fra->x_max - all->fra->x_min) / 2;
		x1 = x / all->fra->zoom_x + all->fra->x_min;
		all->fra->x_min = x1 - e * 1.2;
		all->fra->x_max = x1 + e * 1.2;
		e = (all->fra->y_max - all->fra->y_min) / 2;
		x1 = y / all->fra->zoom_y + all->fra->y_min;
		all->fra->y_min = x1 - e * 1.2;
		all->fra->y_max = x1 + e * 1.2;
		all->fra->zoom_x = all->win->width
			/ (all->fra->x_max - all->fra->x_min);
		all->fra->zoom_y = all->win->height
			/ (all->fra->y_max - all->fra->y_min);
	}
}

void	ft_zoom_out(t_mlx *all, int x, int y)
{
	double e;
	double x1;

	if (all->cam->fractal != 'j')
	{
		all->fra->reve = 0;
		e = (all->fra->x_max - all->fra->x_min) / 2;
		x1 = x / all->fra->zoom_x + all->fra->x_min;
		all->fra->x_min = x1 - e / 1.2;
		all->fra->x_max = x1 + e / 1.2;
		e = (all->fra->y_max - all->fra->y_min) / 2;
		x1 = y / all->fra->zoom_y + all->fra->y_min;
		all->fra->y_min = x1 - e / 1.2;
		all->fra->y_max = x1 + e / 1.2;
		all->fra->zoom_x = all->win->width
			/ (all->fra->x_max - all->fra->x_min);
		all->fra->zoom_y = all->win->height
			/ (all->fra->y_max - all->fra->y_min);
	}
}

int			ft_mouse_press(int key, int x, int y, void *param)
{
	t_mlx	*all;

	all = (t_mlx *)param;
	if (x > all->win->width || x < 0 || y > all->win->height || y < 0)
		return (0);
	if (key == 4)
		ft_zoom_in(all, x, y);
	if (key == 5)
		ft_zoom_out(all, x, y);
	if (key == 1)
		all->cam->mouse_right = 0;
	if (key == 2)
		all->cam->mouse_right = 1;
	ft_render(all);
/*	all->thread->wait = 1;*/

	return (0);
}

int			ft_mouse_release(int key, int x, int y, void *param)
{
	t_mlx	*all;

	all = (t_mlx *)param;
	if (x > all->win->width || x < 0 || y > all->win->height || y < 0)
		return (0);
	key = 0;
	return (0);
}

int			ft_mouse_move(int x, int y, void *param)
{
	t_mlx *all;

	all = (t_mlx *)param;
	if (x > all->win->width || x < 0 || y > all->win->height || y < 0)
		return (0);
	if (all->cam->mouse_right == 0 && all->cam->fractal == 'j')
	{
		all->cam->x_mouse = x;
		all->cam->y_mouse = y;
		ft_render(all);
/*		all->thread->wait = 1;*/
	}
	return (0);
}
