/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:03:33 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/09 16:42:32 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;

	if (!s1)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	if ((copy = (char *)malloc(sizeof(*copy) * (i + 1))) == NULL)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(copy + i) = (char)*(s1 + i);
		i++;
	}
	*(copy + i) = '\0';
	return (copy);
}
