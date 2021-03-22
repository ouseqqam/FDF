/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:19:21 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/10/23 14:35:19 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static		int		nb_mot(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			break ;
	}
	while (str[i])
	{
		if (str[i] == c)
			if (str[i - 1] != c)
				count++;
		i++;
	}
	if (str[i] == '\0')
		if (str[i - 1] != c)
			count++;
	return (count);
}

static		int		nb_car(const char *str, int i, char c)
{
	int count;

	count = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	int		k;
	int		d;
	int		e;
	char	**p;

	k = 0;
	d = 0;
	if (!(s && (p = (char**)malloc(sizeof(char*) * (nb_mot(s, c) + 1)))))
		return (0);
	while (s[d])
	{
		while (s[d] == c)
			d++;
		if (s[d] != '\0')
		{
			if (!(p[k] = (char*)malloc(sizeof(char) * (nb_car(s, d, c) + 1))))
				return (0);
			e = 0;
			while (s[d] != c && s[d])
				p[k][e++] = s[d++];
			p[k++][e] = '\0';
		}
	}
	p[k] = 0;
	return (p);
}
