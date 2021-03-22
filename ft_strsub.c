/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:42:04 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/10/23 19:07:21 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	i = 0;
	j = 0;
	if (s && (p = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (s[i])
		{
			if (i == start)
			{
				while (j < len)
					p[j++] = s[i++];
			}
			if (j == len)
				break ;
			i++;
		}
		p[j] = '\0';
		return (p);
	}
	return (0);
}
