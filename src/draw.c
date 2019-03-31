/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:54:36 by nicktor           #+#    #+#             */
/*   Updated: 2019/03/31 03:14:37 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_render(t_mlx *all)
{
//	ft_bzero((void *)all->win->img_str, all->win->width
//		* all->win->height * 4);
	ft_mandelbrot(all);
	mlx_clear_window(all->mlx_ptr, all->win->win_ptr);
	mlx_put_image_to_window(all->mlx_ptr, all->win->win_ptr,
		all->win->img_ptr, 0, 0);
	ft_legend(all);
} 

void	ft_fill_pixel(t_mlx *all, int x, int y, unsigned int color)
{
	if (x >= 0 && x < all->win->width
		&& y >= 0 && y < all->win->height)
		all->win->img_str[y * all->win->width + x] = color;
}

void	ft_legend(t_mlx *all)
{
	char *nbr;

	nbr = ft_itoa(all->cam->iter);
	mlx_string_put(all->mlx_ptr, all->win->win_ptr, 0, 40, 0xFFFF00, "iter = ");
	mlx_string_put(all->mlx_ptr, all->win->win_ptr, 0, 100, 0xFFFF00, nbr);
	ft_putstr("\n");
	ft_putstr(nbr);
	ft_putstr("\n");
	ft_memdel((void *)&nbr);
}
