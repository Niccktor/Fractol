/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:18:04 by tbeguin           #+#    #+#             */
/*   Updated: 2019/09/05 12:05:17 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	ft_key_color(int key, t_mlx *all)
{
	if (key == ONE_PAD && all->cam.r > 0)
		all->cam.r--;
	if (key == SEVEN_PAD && all->cam.r < 50)
		all->cam.r++;
	if (key == TOW_PAD && all->cam.g > 0)
		all->cam.g--;
	if (key == EIGHT_PAD && all->cam.g < 50)
		all->cam.g++;
	if (key == THREE && all->cam.b > 0)
		all->cam.b--;
	if (key == NINE_PAD && all->cam.b < 50)
		all->cam.b++;
	if (key == Z)
		ft_preset_color(all, 1);
	if (key == X)
		ft_preset_color(all, 2);
	if (key == C)
		ft_preset_color(all, 3);
	if (key == V)
		ft_preset_color(all, 4);
	show_img(all);
	return (0);
}

static int	ft_key_press_next(int key, t_mlx *all)
{
	if (key == LESS_PAD)
		ft_zoom_in(all, all->win.width / 2, all->win.height / 2, 1.2);
	if (key == MORE_PAD)
		ft_zoom_out(all, all->win.width / 2, all->win.height / 2, 1.2);
	if (key == ARROW_UP)
		ft_zoom_in(all, all->win.width / 2, all->win.height / 1.99, 1);
	if (key == ARROW_DOWN)
		ft_zoom_in(all, all->win.width / 2, all->win.height / 2.01, 1);
	if (key == ARROW_LEFT)
		ft_zoom_in(all, all->win.width / 1.99, all->win.height / 2, 1);
	if (key == ARROW_RIGHT)
		ft_zoom_in(all, all->win.width / 2.01, all->win.height / 2, 1);
	if (key == O && all->fra.pow > 2)
		all->fra.pow--;
	if (key == P && all->fra.pow < 100)
		all->fra.pow++;
	if (key == K && all->cam.threads > 1)
		all->cam.threads /= 2;
	if (key == L && all->cam.threads < 256)
		all->cam.threads *= 2;
	return (ft_key_color(key, all));
}

int			ft_key_press(int key, t_mlx *all)
{
	if (key == ESC)
		ft_exit(all);
	if (key == ONE || (key == R && all->fra.fractal == mandelbrot))
		init_mandelbrot(all);
	if (key == TOW || (key == R && all->fra.fractal == julia))
		init_julia(all);
	if (key == THREE || (key == R && all->fra.fractal == ship))
		init_ship(all);
	if (key == FOUR)
		init_julia_preset(all, 1);
	if (key == FIVE)
		init_julia_preset(all, 2);
	if (key == SIX)
		init_julia_preset(all, 3);
	if (key == SEVEN)
		init_julia_preset(all, 4);
	if (key == EIGHT)
		init_julia_preset(all, 5);
	if (key == PAGE_UP && all->fra.iter < 10000)
		all->fra.iter += 100;
	if (key == PAGE_DOWN && all->fra.iter > 100)
		all->fra.iter -= 100;
	return (ft_key_press_next(key, all));
}
