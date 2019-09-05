/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/09/05 12:06:14 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		main(int argc, char **argv)
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
