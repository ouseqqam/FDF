/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <ouseqqam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:52:32 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/11/06 15:57:47 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# define SIZE 300000
# define HEIGHT 1500
# define WIDTH  1000

int				ft_check(int fd);

typedef struct	s_points
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		c;
}				t_points;

typedef	struct	s_tab
{
	int a;
	int c;
}				t_tab;

typedef struct	s_at
{
	int i;
	int j;
	int signe;
	int nb;
	int d;
}				t_at;
typedef	struct	s_check
{
	int		r;
	char	*p;
	char	**s;
	char	**t;
	int		i;
	int		b;
	char	*x;
	int		j;
	int		*k;
	char	tab[SIZE];
	t_tab	**tabl;
}				t_check;

typedef struct	s_br
{
	int			dx;
	int			dy;
	int			p;
	int			sx;
	int			sy;
	void		*mlx_ptr;
	void		*win_ptr;
	int			a;
	int			b;
	t_points	v;
	t_tab		**str;
	int			d;
	int			*tab;
	int			z1;
	int			z2;
	int			i;
	int			j;
	int			f;
	int			g;
	int			h;
	int			l;
	int			m;
	int			ch_p;
	t_check		w;
}				t_br;

int				ft_read(t_br *b, int fd);
void			bresnham_suite(t_br *b);
void			bresnham_suite1(t_br *b);
void			bresnham(t_br *b);
void			print_map_parallel(t_br *b);
void			print_map_iso(t_br *b);
int				key_press(int keycode, void *p);
void			free_2d(t_tab **tab, int n);
void			free_d(char **tab, int n);
void			ft_putendl(char const *s);
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
void			menu(t_br *b);

#endif
