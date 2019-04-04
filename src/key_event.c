/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:18:04 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/04 22:36:03 by tbeguin          ###   ########.fr       */
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
	if (key == 125 || key == 126 || key == 38 || key == 46 || key == 15)
		ft_key_cam(key, all);
	return (0);
}
