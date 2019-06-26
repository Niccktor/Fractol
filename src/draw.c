/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:54:36 by nicktor           #+#    #+#             */
/*   Updated: 2019/06/26 04:00:21 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	show_img(t_mlx *all)
{
	threads(*all);
	mlx_put_image_to_window(all->mlx_ptr, all->win.win_ptr,
			all->win.img_ptr, 0, 0);
	ft_legend(all);
}

void	ft_fill_pixel(t_mlx *all, int x, int y, unsigned int color)
{
	if (x >= 0 && x < all->win.width
		&& y >= 0 && y < all->win.height)
		all->win.img_str[y * all->win.width + x] = color;
}

void	ft_legend(t_mlx *all)
{
	char *nbr;

	nbr = ft_itoa(all->fra.iter);
	mlx_string_put(all->mlx_ptr, all->win.win_ptr, 0, 40, 0xFF0000, "iter = ");
	mlx_string_put(all->mlx_ptr, all->win.win_ptr, 100, 40, 0xFF0000, nbr);
	ft_memdel((void *)&nbr);
}
