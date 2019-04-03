/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/03 21:39:54 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
/*
static void	ft_print(int key, int x, int y)
{
	ft_putstr("----------------------mouse--------------------\n");
	ft_putnbr(key);
	ft_putstr("\n");
	ft_putnbr(x);
	ft_putstr("\n");
	ft_putnbr(y);
	ft_putstr("\n");
	ft_putstr("-----------------------------------------------\n");
}*/

int		ft_mouse_press(int key, int x, int y, void *param)
{
	t_mlx	*all;

	all = (t_mlx *)param;
	if (x > all->win->width || x < 0 || y > all->win->height || y < 0)
		return (0);
	if (key == 4)
	{
	}
	if (key == 5)
	{

	}
	if (key == 1)
		all->cam->mouse_left = 1;
	if (key == 2)
		all->cam->mouse_right = 1;
/*	ft_print(key, x, y);*/
	return (0);
}

int		ft_mouse_release(int key, int x, int y, void *param)
{
	t_mlx	*all;

	all = (t_mlx *)param;
	if (x > all->win->width || x < 0 || y > all->win->height || y < 0)
		return (0);

	if (key == 1)
		all->cam->mouse_left = 0;
	if (key == 2)
		all->cam->mouse_right = 0;
	return (0);
}

int		ft_mouse_move (int x, int y, void *param)
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
	}
	return (0);
}
