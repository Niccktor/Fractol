/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:29:34 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/03 18:29:49 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

t_complex		ft_new_complex(double re, double ir)
{
	t_complex z;

	z.re = re;
	z.ir = ir;
	return (z);
}

void			ft_complex_calc(t_complex *z, t_complex c)
{
	double tmp;

	tmp = z->re;
	z->re = z->re * z->re - z->ir * z->ir + c.re;
	z->ir = 2 * z->ir * tmp + c.ir;
}

double			ft_complex_mod(t_complex z)
{
	double tmp;

	tmp = z.re * z.re - z.ir * z.ir;
	if (tmp < 0)
		tmp *= -1;
	return (sqrtf(tmp));
}
