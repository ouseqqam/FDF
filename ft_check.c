/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:18:47 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/11/06 16:00:51 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_suite(char *line, int *c, int fd)
{
	int j;

	j = -1;
	if (get_next_line(fd, &line) <= 0)
	{
		ft_putendl("No data found.");
		return (0);
	}
	while (line[++j])
		if (line[j] > 32 && line[j] < 127)
			(*c)++;
	free(line);
	if (*c == 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int		ft_check(int fd)
{
	char	*line;
	int		j;
	int		c;

	c = 0;
	line = NULL;
	free(line);
	if (!check_suite(line, &c, fd))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		while (line[++j])
			if (line[j] > 32 && line[j] < 127)
				c++;
		free(line);
	}
	if (c == 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
