/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/03 19:40:00 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


static void	ft_key_cam(int key, t_mlx *all)
{
	if (key == 125 && all->cam->iter > 100)
		all->cam->iter -= 100;
	else if (key == 126 && all->cam->iter < 5000)
		all->cam->iter += 100;
	else if (key == 38)
		all->cam->fractal = 'j';
	else if (key == 46)
		all->cam->fractal = 'm';
	ft_render(all);
}

int		ft_key_hook(int key, void *para)
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



	ft_putstr("----------------------key----------------------\n");
	ft_putnbr(key);
	ft_putstr("\n");
	ft_putstr("-----------------------------------------------\n");
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, void *para)
{
	t_mlx		*all;

	all = (t_mlx *)para;
	ft_putstr("----------------------mouse--------------------\n");
	ft_putnbr(button);
	ft_putstr("\n");
	ft_putnbr(x);
	ft_putstr("\n");
	ft_putnbr(y);
	ft_putstr("\n");
	ft_putstr("-----------------------------------------------\n");
	return (0);
}
