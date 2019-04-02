/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:32:28 by ariperez          #+#    #+#             */
/*   Updated: 2019/03/21 17:24:41 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		negative;
	int		number;

	i = 0;
	negative = 1;
	while ((9 <= *(str + i) && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*(str + i) == '+')
		i++;
	else if (*(str + i) == '-')
	{
		negative = -1;
		i++;
	}
	number = 0;
	while ('0' <= *(str + i) && *(str + i) <= '9')
	{
		number *= 10;
		number += (*(str + i) - '0');
		i++;
	}
	return (negative * number);
}
