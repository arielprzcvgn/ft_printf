/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:38:14 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/21 18:41:17 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strnew(size_t size)
{
	char		*str;

	if ((str = (char *)malloc(sizeof(*str) * (size + 1))) == NULL)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
