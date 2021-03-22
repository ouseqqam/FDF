/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:48:58 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/11/06 16:01:06 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_myatoi(char *str)
{
	t_at a;

	a.i = 0;
	a.j = -1;
	a.signe = 1;
	a.nb = 0;
	while (str[a.i] != 'x' && str[a.i])
		a.i++;
	if (str[a.i] != 'x')
		return (0);
	while (str[++(a.i)])
		a.j++;
	a.i = a.i - a.j - 1;
	while ((str[a.i] >= '0' && str[a.i] <= '9') ||
			(str[a.i] >= 'A' && str[a.i] <= 'F'))
	{
		if (str[a.i] >= '0' && str[a.i] <= '9')
			a.d = str[a.i] - '0';
		else
			a.d = str[a.i] - 55;
		a.nb = a.nb + (pow(16, (a.j)--) * a.d);
		a.i++;
	}
	return (a.nb * a.signe);
}

void	ft_read_suite2(t_br *b)
{
	while (b->w.b < b->w.j && (b->w.t[b->w.b] != NULL))
	{
		if (ft_myatoi(b->w.t[b->w.b]) == 0 && ft_atoi(b->w.t[b->w.b]) == 0)
			b->w.r = 16777215;
		else if (ft_myatoi(b->w.t[b->w.b]) == 0 && ft_atoi(b->w.t[b->w.b]) != 0)
			b->w.r = 255;
		else
			b->w.r = ft_myatoi(b->w.t[b->w.b]);
		b->w.tabl[b->w.i][b->w.b].a = ft_atoi(b->w.t[b->w.b]);
		b->w.tabl[b->w.i][b->w.b].c = b->w.r;
		b->w.b++;
	}
}

int		ft_read_suite(t_br *b)
{
	while (b->w.s[b->w.i] != NULL)
	{
		b->w.t = ft_strsplit(b->w.s[b->w.i], ' ');
		b->w.j = 0;
		while (b->w.t[b->w.j] != NULL)
			b->w.j++;
		b->w.k[b->w.i] = b->w.j;
		if (b->w.i > 0 && b->w.k[b->w.i] < b->w.k[0])
		{
			ft_putendl("Found wrong line length. Exiting.");
			free_2d(b->w.tabl, b->w.i);
			free_d(b->w.t, b->w.j);
			free_d(b->w.s, b->d);
			free(b->w.k);
			return (0);
		}
		if (!(b->w.tabl[b->w.i] = (t_tab*)malloc(sizeof(t_tab) * b->w.j)))
			return (0);
		b->w.b = 0;
		ft_read_suite2(b);
		b->w.i++;
		free_d(b->w.t, b->w.j);
	}
	return (1);
}

void	ft_read_suite3(t_br *b, int fd)
{
	while ((b->w.r = read(fd, b->w.tab, SIZE)) > 0)
	{
		b->w.tab[b->w.r] = '\0';
		b->w.x = ft_strjoin(b->w.p, b->w.tab);
		free(b->w.p);
		b->w.p = b->w.x;
	}
}

int		ft_read(t_br *b, int fd)
{
	b->d = 0;
	b->w.i = 0;
	b->w.p = ft_strnew(0);
	ft_read_suite3(b, fd);
	b->w.s = ft_strsplit(b->w.p, '\n');
	free(b->w.p);
	while (b->w.s[b->d] != NULL)
		b->d++;
	if (!(b->w.tabl = (t_tab**)malloc(sizeof(t_tab*) * b->d)))
		return (0);
	if (!(b->w.k = (int*)malloc(sizeof(int) * b->d)))
	{
		free(b->w.tabl);
		return (0);
	}
	if (!ft_read_suite(b))
		return (0);
	free_d(b->w.s, b->d);
	b->str = b->w.tabl;
	b->tab = b->w.k;
	return (1);
}
