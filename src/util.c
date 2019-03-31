/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/03/31 01:32:40 by nicktor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_mlx	*ft_new_mlx()
{
	t_mlx	*new;

	if ((new = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((new->mlx_ptr = mlx_init()) == NULL)
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

t_mlx	*ft_new_win(t_mlx *all, char *s, int width, int height)
{
	int bpp;
	int s_l;
	int endian;

	if ((all->win = (t_win *)ft_memalloc(sizeof(t_win))) == NULL)
	{	
		ft_memdel((void **)&(all->mlx_ptr));
		ft_memdel((void **)&all);
		return (NULL);
	}
	if ((all->win->img_ptr = mlx_new_image(all->mlx_ptr, width, height)) == NULL)
		ft_close("Erreur malloc img");
	all->win->img_str =
		(unsigned int *)mlx_get_data_addr(all->win->img_ptr, &bpp, &s_l, &endian);
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
	all->cam->color = 0x010101;
	all->cam->color_end = 0;
	all->cam->iter = 100;
	return (all);
}
