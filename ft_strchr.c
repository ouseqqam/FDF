/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:58:45 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/10/23 19:05:17 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)s;
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)(s + i));
		i++;
	}
	if (p[i] == (char)c)
		return ((char*)(p + i));
	return (0);
}
