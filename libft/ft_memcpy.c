/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:36:34 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/27 14:17:19 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}
