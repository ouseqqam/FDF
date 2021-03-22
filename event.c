/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:55 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/11/02 11:33:01 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_set(t_br *b)
{
	if (b->z2 > 0)
	{
		mlx_clear_window(b->mlx_ptr, b->win_ptr);
		print_map_iso(b);
		menu(b);
	}
}

void	altitude_zoom(t_br *b, int keycode)
{
	if (keycode == 116)
	{
		b->g += 5;
		clear_set(b);
	}
	if (keycode == 121)
	{
		b->g -= 5;
		clear_set(b);
	}
	if (keycode == 69)
	{
		b->z1 += 1;
		clear_set(b);
	}
	if (keycode == 78)
	{
		if (b->z1 > 0)
			b->z1 -= 1;
		if (b->z1 > 0)
			clear_set(b);
	}
}

void	direction(t_br *b, int keycode)
{
	if (keycode == 124)
	{
		b->f += 150;
		clear_set(b);
	}
	if (keycode == 123)
	{
		b->f -= 150;
		clear_set(b);
	}
	if (keycode == 125)
	{
		b->h -= 150;
		clear_set(b);
	}
	if (keycode == 126)
	{
		b->h += 150;
		clear_set(b);
	}
}

void	multi(t_br *b, int keycode)
{
	if (keycode == 36 && b->ch_p == 0)
	{
		if (b->z2 > 0)
		{
			b->l += 10000;
			clear_set(b);
		}
	}
	if (keycode == 53)
	{
		free_2d(b->str, b->d);
		free(b->tab);
		free(b);
		exit(0);
	}
}

int		key_press(int keycode, void *p)
{
	t_br	*b;

	b = (t_br *)p;
	if (b->ch_p == 0)
	{
		if (keycode == 34)
		{
			(b->z2)++;
			mlx_clear_window(b->mlx_ptr, b->win_ptr);
			print_map_iso(b);
			menu(b);
		}
		if (keycode == 35)
		{
			b->z2 = 0;
			mlx_clear_window(b->mlx_ptr, b->win_ptr);
			print_map_parallel(b);
			menu(b);
		}
		direction(b, keycode);
		altitude_zoom(b, keycode);
	}
	multi(b, keycode);
	return (0);
}
