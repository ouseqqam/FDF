/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:56:08 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/10/26 15:50:01 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_br *b)
{
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 50, 255, "           main menu");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 70, 255,
			"---------------------------------");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 100, 255, "  Isometrie = I");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 120, 255, "  Parallele : P");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 140, 255
			, "  + : zoom / - : dezoom");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 160, 255, "  up : sahm lfoqani");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 180, 255
			, "  down : sahm ltahtani");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 200, 255
			, "  right : sahm limni");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 220, 255
			, "  left : sahm lisri");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 240, 255
			, "  altitude++ : page up");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 260, 255
			, "  altitude-- : page down");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 280, 255, "  close : esc");
	mlx_string_put(b->mlx_ptr, b->win_ptr, 50, 300, 255
			, "  entree : change color");
}
