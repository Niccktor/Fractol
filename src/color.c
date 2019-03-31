/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicktor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 01:21:06 by nicktor           #+#    #+#             */
/*   Updated: 2019/03/31 01:42:44 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

unsigned int	ft_get_color(t_mlx *all, int i)
{
	unsigned int color;

	if (i > all->cam->iter)
		return (all->cam->color_end);
	color = (i * 10) * all->cam->color;
	color = (color << 8) + (255 - (i * 2) * all->cam->color);
	color = (color << 8) + (255 - (i * 5) * all->cam->color);
	return (color);
}
