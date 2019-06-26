/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:20:17 by tbeguin           #+#    #+#             */
/*   Updated: 2019/06/26 05:03:07 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <stdio.h>

void		threads(t_mlx all)
{
	int			i;
	t_thread	threads[256];

	i = 0;
	while (i < all.cam.threads)
	{
		threads[i].i = i;
		threads[i].all = all;
		pthread_create(&threads[i].thread, NULL,
				all.fra.fractal, &threads[i]);
		i++;
	}
	i = 0;
	while (i < all.cam.threads)
		pthread_join(threads[i++].thread, NULL);
}
