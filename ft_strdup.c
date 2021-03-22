/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:03:52 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/10/23 19:04:41 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			*ft_strdup(const char *str)
{
	size_t		i;
	int			j;
	char		*p;

	j = 0;
	i = ft_strlen(str);
	if ((p = (char*)malloc(sizeof(char) * (i + 1))))
	{
		while (str[j])
		{
			p[j] = str[j];
			j++;
		}
		p[j] = '\0';
		return (p);
	}
	return (0);
}
