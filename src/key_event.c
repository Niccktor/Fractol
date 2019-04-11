/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:18:04 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/11 18:16:29 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_key_cam(int key, t_mlx *all)
{
	if (key == 125 && all->fra->iter > 100)
		all->fra->iter -= 100;
	else if (key == 126 && all->fra->iter < 5000)
		all->fra->iter += 100;
	else if (key == 38)
		all->cam->fractal = 'j';
	else if (key == 46)
		all->cam->fractal = 'm';
	else if (key == 1)
		all->cam->fractal = 's';
	ft_render(all);
}

static void	ft_key_color(int key, t_mlx *all)
{
	if (key == 121 && all->cam->o > 0)
		all->cam->o -= 1;
	if (key == 116 && all->cam->o < 200)
		all->cam->o += 1;
	if (key == 83 && all->cam->r > 0)
		all->cam->r--;
	if (key == 89 && all->cam->r < 50)
		all->cam->r++;
	if (key == 84 && all->cam->g > 0)
		all->cam->g--;
	if (key == 91 && all->cam->g < 50)
		all->cam->g++;
	if (key == 85 && all->cam->b > 0)
		all->cam->b--;
	if (key == 92 && all->cam->b < 50)
		all->cam->b++;
	ft_render(all);
}

static void	ft_key_move(int key, t_mlx *all)
{
	if (key == 78)
		ft_zoom_in(all, all->win->width / 2, all->win->height / 2);
	if (key == 69)
		ft_zoom_out(all, all->win->width / 2, all->win->height / 2);
	ft_render(all);
}

int			ft_key_hook(int key, void *para)
{
	t_mlx *all;

	all = (t_mlx *)para;
	if (key == 53)
	{
		mlx_destroy_window(all->mlx_ptr, all->win->win_ptr);
		exit(0);
		return (1);
	}
	if (key == 125 || key == 126 || key == 38 || key == 46 || key == 15
			|| key == 1)
		ft_key_cam(key, all);
	if (key == 83 || key == 89 || key == 84 || key == 91 || key == 85 ||
			key == 92 || key == 121 || key == 116)
		ft_key_color(key, all);
	if (key == 84 || key == 86 || key == 88 || key == 91 || key == 78|| key == 69)
		ft_key_move(key, all);
	return (0);
}
