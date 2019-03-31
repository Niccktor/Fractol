/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/31 00:48:24 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

#define BLUE 0x0A5FE8
#define WHITE 0xFFFFFF

int 	ft_key_hook(int key, void *para)
{
	t_mlx *all;

	all = (t_mlx *)para;
	if (key == 65307)
	{
		mlx_destroy_window(all->mlx_ptr, all->win->win_ptr);
		exit(0);
		return (1);
	}
	if (key == 114)/*	R	*/
		ft_render(all);
	if (key == 65362)/*	arrow up	*/
	{
		all->cam->iter += 100;
		ft_render(all);
	}
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
