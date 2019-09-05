/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 01:21:06 by nicktor           #+#    #+#             */
/*   Updated: 2019/09/05 12:03:19 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

unsigned int	ft_get_color(t_mlx *all, int i)
{
	unsigned int color;
	unsigned int tmp;

	if (i >= all->fra.iter)
		return (all->cam.color_end);
	tmp = (i * all->cam.o) % 0xFF;
	color = tmp;
	tmp = (i * all->cam.r) % 0xFF;
	color = (color << 8) + tmp;
	tmp = (i * all->cam.g) % 0xFF;
	color = (color << 8) + tmp;
	tmp = (i * all->cam.b) % 0xFF;
	color = (color << 8) + tmp;
	return (color);
}

void			ft_preset_color(t_mlx *all, int i)
{
	if (i == 1)
	{
		all->cam.r = 10;
		all->cam.g = 0;
		all->cam.b = 0;
	}
	if (i == 2)
	{
		all->cam.r = 0;
		all->cam.g = 10;
		all->cam.b = 0;
	}
	if (i == 3)
	{
		all->cam.r = 0;
		all->cam.g = 0;
		all->cam.b = 10;
	}
	if (i == 4)
	{
		all->cam.r = 2;
		all->cam.g = 5;
		all->cam.b = 10;
	}
}
