/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:12:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/05/28 16:26:09 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	*ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = b;
	i = 0;
	while (i < len)
	{
		*(p + i) = 0;
		i++;
	}
	return (b);
}
