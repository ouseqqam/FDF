/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:16:25 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/11/02 11:34:17 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initiale(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 1;
}

int		event(t_br *b, int fd)
{
	if (!ft_read(b, fd))
	{
		free(b);
		close(fd);
		exit(0);
	}
	b->mlx_ptr = mlx_init();
	b->win_ptr = mlx_new_window(b->mlx_ptr, HEIGHT, WIDTH, "fdf");
	if (b->d == 1 && b->tab[0] == 1)
	{
		mlx_pixel_put(b->mlx_ptr, b->win_ptr, b->v.x0 + HEIGHT / 2
				, b->v.y0 + WIDTH / 2, 255);
		(b->ch_p)++;
	}
	else
	{
		print_map_parallel(b);
		menu(b);
	}
	close(fd);
	mlx_hook(b->win_ptr, 2, 0, key_press, (void *)b);
	mlx_loop(b->mlx_ptr);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_br	*b;

	b = NULL;
	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if ((!ft_check(fd)) || !(b = (t_br *)malloc(sizeof(t_br))))
	{
		close(fd);
		return (0);
	}
	b->l = 0;
	b->m = 0;
	b->ch_p = 0;
	close(fd);
	initiale(&b->z2, &b->h, &b->f, &b->g);
	fd = open(av[1], O_RDONLY);
	event(b, fd);
	return (0);
}
