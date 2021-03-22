/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:03:26 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/11/01 19:48:44 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_suite_par_2(t_br *b)
{
	if (b->i < b->d - 1)
	{
		b->v.x0 = b->j * b->z1 - b->a;
		b->v.x1 = b->j * b->z1 - b->a;
		b->v.y0 = b->i * b->z1 - b->b;
		b->v.y1 = (b->i + 1) * b->z1 - b->b;
		if (b->str[b->i][b->j].a == 0 && b->str[b->i + 1][b->j].a != 0)
			b->v.c = b->str[b->i + 1][b->j].c;
		else if (b->str[b->i][b->j].a != 0 && b->str[b->i][b->j].a == 0)
			b->v.c = b->str[b->i][b->j].c;
		else
			b->v.c = b->str[b->i][b->j].c;
		bresnham(b);
	}
}

void	print_suite_par(t_br *b)
{
	if (b->j < b->tab[b->i] - 1)
	{
		b->v.x0 = b->j * b->z1 - b->a;
		b->v.x1 = (b->j + 1) * b->z1 - b->a;
		b->v.y0 = b->i * b->z1 - b->b;
		b->v.y1 = b->i * b->z1 - b->b;
		if (b->str[b->i][b->j].a == 0 && b->str[b->i][b->j + 1].a != 0)
			b->v.c = b->str[b->i][b->j + 1].c;
		else if (b->str[b->i][b->j].a != 0 && b->str[b->i][b->j].a == 0)
			b->v.c = b->str[b->i][b->j].c;
		else
			b->v.c = b->str[b->i][b->j].c;
		bresnham(b);
	}
	print_suite_par_2(b);
}

void	print_map_parallel(t_br *b)
{
	b->z1 = (HEIGHT / (2 * b->tab[0]));
	b->i = -1;
	b->a = (b->tab[0] * b->z1) / 2 - (HEIGHT / 2);
	b->b = (b->d * b->z1) / 2 - (WIDTH / 2);
	while (++(b->i) < b->d)
	{
		b->j = -1;
		while (++(b->j) < b->tab[b->i])
			print_suite_par(b);
	}
}
