/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/04/11 16:00:31 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_mlx	*ft_new_mlx(void)
{
	t_mlx	*new;

	if ((new = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((new->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
/*	if ((new->thread = (t_thread *)ft_memalloc(sizeof(t_thread))) == NULL)
		return (NULL);*/
	return (new);
}

t_mlx	*ft_new_win(t_mlx *all, char *s, int width, int height)
{
	int bpp;
	int s_l;
	int endian;

	if ((all->win = (t_win *)ft_memalloc(sizeof(t_win))) == NULL)
		return (NULL);
	if ((all->win->img_ptr = mlx_new_image(all->mlx_ptr, width, height))
			== NULL)
		return (NULL);
	all->win->img_str =
		(unsigned int *)mlx_get_data_addr(all->win->img_ptr,
				&bpp, &s_l, &endian);
	all->win->name = s;
	all->win->width = width;
	all->win->height = height;
	all->win->win_ptr = mlx_new_window(all->mlx_ptr,
			all->win->width, all->win->height, all->win->name);
	return (all);
}

t_mlx	*ft_new_cam(t_mlx *all)
{
	if ((all->cam = (t_cam *)ft_memalloc(sizeof(t_cam))) == NULL)
		ft_close("Malloc cam error");
	all->cam->fractal = 'm';
	all->cam->mouse_left = 0;
	all->cam->mouse_right = 0;
	all->cam->y_mouse = 0;
	all->cam->x_mouse = 0;
	all->cam->o = 0;
	all->cam->r = 10;
	all->cam->g = 2;
	all->cam->b = 5;
	all->cam->color = 0x00001;
	all->cam->color_end = 0;
	return (all);
}

t_mlx	*ft_new_fract(t_mlx *all)
{
	if ((all->fra = (t_fract *)ft_memalloc(sizeof(t_fract))) == NULL)
		ft_close("Malloc fract error");
	all->fra->x_min = -2.2;
	all->fra->x_max = 2.2;
	all->fra->y_min = -2.2;
	all->fra->y_max = 2.2;
	all->fra->zoom_x = all->win->width / (all->fra->x_max - all->fra->x_min);
	all->fra->zoom_y = all->win->height / (all->fra->y_max - all->fra->y_min);
	all->fra->iter = 10;
	all->fra->reve = 1;
	return (all);
}
/*
void 	*ft_thread_render(void *arg)
{
	t_mlx *all;
	int i;

	all = (t_mlx *)arg;
	i = all->thread->nb;
	all->thread->nb++;
	while (all->thread->exit)
	{
		if (all->thread->wait)
			ft_render(all,
					all->win->width / 4 * (i + 1), all->win->height / 4 * (i + 1));
	}
	pthread_exit(NULL);
}

t_mlx	*ft_new_thread(t_mlx *all)
{
	int i;

	if ((all->thread = (t_thread *)ft_memalloc(sizeof(t_thread))) == NULL)
		return (NULL);
	all->thread->wait = 0;
	all->thread->exit = 1;
	all->thread->nb = 0;
	if ((all->thread->thread
				= (pthread_t **)ft_memalloc(sizeof((pthread_t *) 4))) == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if ((all->thread->thread[i]
					= (pthread_t *)ft_memalloc(sizeof(pthread_t))) == NULL)
			return (NULL);
		if (pthread_create(all->thread->thread[i] , NULL, ft_thread_render, all))
			return (NULL);
		i++;
	}
	return (all);
}*/
