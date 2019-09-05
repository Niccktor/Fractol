/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:29:34 by tbeguin           #+#    #+#             */
/*   Updated: 2019/09/05 12:07:52 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

t_complex	ft_new_complex(double re, double ir)
{
	t_complex z;

	z.re = re;
	z.ir = ir;
	return (z);
}

double		ft_complex_mod(t_complex z)
{
	double tmp;

	tmp = z.re * z.re - z.ir * z.ir;
	if (tmp < 0)
		tmp *= -1;
	return (sqrtf(tmp));
}

t_point		ft_new_point(int x, int y)
{
	t_point new;

	new.x = x;
	new.y = y;
	return (new);
}

double		power(double a, int pow)
{
	double new;

	new = 1;
	while (pow)
	{
		new = new * a;
		pow--;
	}
	return (new);
}
