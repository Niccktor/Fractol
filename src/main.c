/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/26 04:38:10 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
/*
int	main(int argc, char **argv)
{
	t_mlx	*all;

	if (argc != 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" < Mandelbrot | Julia | Ship >\n");
		return (-1);
	}
	if ((all = ft_new_mlx()) == NULL)
		ft_close("Erreur malloc mlx");
	if ((all = ft_new_win(all, argv[0], 1080, 1080)) == NULL)
		ft_close("Erreur malloc win");
	if ((all = ft_new_cam(all, argv[1])) == NULL)
		ft_close("Erreur malloc win");
	if ((all = ft_new_fract(all)) == NULL)
		ft_close("Erreur malloc fract");
	threads(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win->win_ptr, all->win->img_ptr, 0, 0);
	ft_render(all);
	mlx_key_hook(all->win->win_ptr, ft_key_hook, (void *)all);
	mlx_hook(all->win->win_ptr, 17, 0, ft_close, NULL);
	mlx_hook(all->win->win_ptr, 4, 0, ft_mouse_press, (void *)all);
	mlx_hook(all->win->win_ptr, 5, 0, ft_mouse_release, (void *)all);
	mlx_hook(all->win->win_ptr, 6, 0, ft_mouse_move, (void *)all);
	mlx_loop(all->mlx_ptr);
	return (0);
}
*/

int	main(int argc, char **argv)
{
	t_mlx all;
	
	all.name = argv[0];
	if (argc != 2)
		argv_err(&all);
	init_all(&all, argv[1]);
	if (all.fra.fractal == NULL)
		argv_err(&all);
	init_win(&all);
	mlx_loop(all.mlx_ptr);
	return (0);
}

int		argv_err(t_mlx *all)
{
	ft_putstr("Usage : ");
	ft_putstr(all->name);
	ft_putstr("< [Mandelbrot] | [Julia] | [Ship] >\n");
	exit(0);
	return (0);
}

int		ft_exit(t_mlx *all)
{
	mlx_destroy_window(all->mlx_ptr, all->win.win_ptr);
	exit(0);
	return (0);
}
