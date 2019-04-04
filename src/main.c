/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/04 22:20:07 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	*all;

	argc = 0;
	argv[0][0] = '\0';
	if ((all = ft_new_mlx()) == NULL)
		return (-1);
	if ((all = ft_new_win(all, "Mandelbrot", 1080, 1080)) == NULL)
		ft_close("Erreur malloc win");
	if ((all = ft_new_cam(all)) == NULL)
		ft_close("Erreur malloc win");
	if ((all = ft_new_fract(all)) == NULL)
		ft_close("Erreur malloc fract");
	ft_render(all);
	mlx_key_hook(all->win->win_ptr, ft_key_hook, (void *)all);
	mlx_hook(all->win->win_ptr, 17, 0, ft_close, 0);
	mlx_hook(all->win->win_ptr, 4, 0, ft_mouse_press, (void *)all);
	mlx_hook(all->win->win_ptr, 5, 0, ft_mouse_release, (void *)all);
	mlx_hook(all->win->win_ptr, 6, 0, ft_mouse_move, (void *)all);
	return (0);
}

int	ft_close(char *e)
{
	ft_putstr(e);
	ft_putstr("\n");
	exit(0);
}
