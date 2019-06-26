/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 02:05:11 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/26 06:29:40 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_all(t_mlx *all, char *argv)
{
	ft_bzero(all, sizeof(t_mlx));
	all->win.width = 1080;
	all->win.height = 1080;
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		init_mandelbrot(all);
	else if (ft_strcmp(argv, "Julia") == 0)
		init_julia(all);
	else if (ft_strcmp(argv, "Ship") == 0)
		init_ship(all);
}

void	init_cam(t_cam *cam)
{
	cam->mouse_left = 0;
	cam->mouse_right = 0;
	cam->x_mouse = 400;
	cam->y_mouse = 600;
	cam->color = 0x00001;
	cam->o = 0;
	cam->r = 10;
	cam->g = 2;
	cam->b = 5;
	cam->color_end = 0;
	cam->threads = 16;
}

void	init_win(t_mlx *all)
{
	int bpp;
	int s_l;
	int endian;

	all->mlx_ptr = mlx_init();
	all->win.win_ptr = mlx_new_window(all->mlx_ptr, all->win.width,
			all->win.height, "Frac'ol tbeguin@42");
	all->win.img_ptr = mlx_new_image(all->mlx_ptr, all->win.width,
			all->win.height);
	all->win.img_str =(unsigned int *)mlx_get_data_addr(all->win.img_ptr,
			&bpp, &s_l, &endian);
	mlx_hook(all->win.win_ptr, 17 , (1L << 0), ft_exit, all);
	mlx_hook(all->win.win_ptr, 2, 0, ft_key_press, all);
	mlx_hook(all->win.win_ptr, 4, 0, ft_mouse_press, all);
	mlx_hook(all->win.win_ptr, 5, 0, ft_mouse_release, all);
	mlx_hook(all->win.win_ptr, 6, 0, ft_mouse_move, all);
	show_img(all);
}
