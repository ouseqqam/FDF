/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:10:02 by ouseqqam          #+#    #+#             */
/*   Updated: 2019/10/23 14:28:59 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strnew(size_t size)
{
	char	*p;

	if ((p = (char*)malloc(sizeof(char) * (size + 1))))
	{
		ft_bzero(p, size + 1);
		return (p);
	}
	return (NULL);
}
