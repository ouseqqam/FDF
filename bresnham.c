/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresnham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:26:02 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/11/06 15:57:53 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresnham(t_br *b)
{
	b->dx = abs(b->v.x1 - b->v.x0);
	b->sx = b->v.x0 < b->v.x1 ? 1 : -1;
	b->dy = abs(b->v.y1 - b->v.y0);
	b->sy = b->v.y0 < b->v.y1 ? 1 : -1;
	if (b->dy <= b->dx)
		bresnham_suite1(b);
	else if (b->dx <= b->dy)
		bresnham_suite(b);
}

void	bresnham_suite1(t_br *b)
{
	b->p = 2 * b->dy - b->dx;
	while (1)
	{
		if (b->v.x0 == b->v.x1 && b->v.y0 == b->v.y1)
			break ;
		mlx_pixel_put(b->mlx_ptr, b->win_ptr, b->v.x0, b->v.y0, b->v.c);
		if (b->p >= 0)
		{
			b->p = b->p + 2 * b->dy - 2 * b->dx;
			b->v.y0 += b->sy;
		}
		else if (b->p < 0)
			b->p = b->p + 2 * b->dy;
		b->v.x0 += b->sx;
	}
}

void	bresnham_suite(t_br *b)
{
	b->p = 2 * b->dx - b->dy;
	while (1)
	{
		if (b->v.x0 == b->v.x1 && b->v.y0 == b->v.y1)
			break ;
		mlx_pixel_put(b->mlx_ptr, b->win_ptr, b->v.x0, b->v.y0, b->v.c);
		if (b->p >= 0)
		{
			b->p = b->p + 2 * b->dx - 2 * b->dy;
			b->v.x0 += b->sx;
		}
		else if (b->p < 0)
			b->p = b->p + 2 * b->dx;
		b->v.y0 += b->sy;
	}
}
