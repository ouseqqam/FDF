/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:39:17 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/10/26 15:45:52 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599) + (HEIGHT / 2);
	*y = -z + (previous_x + previous_y) * sin(0.523599) + (WIDTH / 2);
}

void	print_suite_iso_2(t_br *b)
{
	if (b->i < b->d - 1)
	{
		b->v.x0 = b->j * b->z1 - b->a;
		b->v.x1 = b->j * b->z1 - b->a;
		b->v.y0 = b->i * b->z1 - b->b;
		b->v.y1 = (b->i + 1) * b->z1 - b->b;
		if (b->str[b->i][b->j].a == 0 && b->str[b->i + 1][b->j].a != 0)
			b->v.c = b->str[b->i + 1][b->j].c + b->l;
		else if (b->str[b->i][b->j].a != 0 && b->str[b->i][b->j].a == 0)
			b->v.c = b->str[b->i][b->j].c + b->l;
		else
			b->v.c = b->str[b->i][b->j].c + b->l;
		iso(&b->v.x0, &b->v.y0, b->str[b->i][b->j].a * b->g + b->h);
		iso(&b->v.x1, &b->v.y1, b->str[b->i + 1][b->j].a * b->g + b->h);
		b->v.x0 += b->f;
		b->v.x1 += b->f;
		bresnham(b);
	}
}

void	print_suite_iso(t_br *b)
{
	if (b->j < b->tab[b->i] - 1)
	{
		b->v.x0 = b->j * b->z1 - b->a;
		b->v.x1 = (b->j + 1) * b->z1 - b->a;
		b->v.y0 = b->i * b->z1 - b->b;
		b->v.y1 = b->i * b->z1 - b->b;
		if (b->str[b->i][b->j].a == 0 && b->str[b->i][b->j + 1].a != 0)
			b->v.c = b->str[b->i][b->j + 1].c + b->l;
		else if (b->str[b->i][b->j].a != 0 && b->str[b->i][b->j].a == 0)
			b->v.c = b->str[b->i][b->j].c + b->l;
		else
			b->v.c = b->str[b->i][b->j].c + b->l;
		iso(&b->v.x0, &b->v.y0, b->str[b->i][b->j].a * b->g + b->h);
		iso(&b->v.x1, &b->v.y1, b->str[b->i][b->j + 1].a * b->g + b->h);
		b->v.x0 += b->f;
		b->v.x1 += b->f;
		bresnham(b);
	}
	print_suite_iso_2(b);
}

void	print_map_iso(t_br *b)
{
	b->i = -1;
	b->a = ((b->tab[0] * b->z1) / 2);
	b->b = (b->d * b->z1) / 2;
	while (++(b->i) < b->d)
	{
		b->j = -1;
		while (++(b->j) < b->tab[b->i])
			print_suite_iso(b);
	}
}
