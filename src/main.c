/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/31 00:56:20 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_parse_map(char *file, t_mlx *all);

int		main(int argc, char **argv)
{
	t_mlx	*all;

	if ((all = ft_new_mlx()) == NULL)
		return (-1);
	if ((all = ft_new_win(all, "Mandelbrot", 1920, 1080)) == NULL)
		ft_close("Erreur malloc win");
	if ((all = ft_new_cam(all)) == NULL)
		ft_close("Erreur malloc win");
	ft_render(all);
	mlx_key_hook(all->win->win_ptr, ft_key_hook, (void *)all);
	mlx_mouse_hook(all->win->win_ptr, ft_mouse_hook, (void *)all);
	mlx_loop(all->mlx_ptr);
	return (0);
}

void		ft_close(char *e)
{
	ft_putstr(e);
	ft_putstr("\n");
	exit(0);

}
