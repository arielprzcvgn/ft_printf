/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:59:32 by ariperez          #+#    #+#             */
/*   Updated: 2019/03/23 23:35:51 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	char	*exception(void)
{
	char	*number;

	if ((number = (char *)malloc(sizeof(*number) * 12)) == NULL)
		return (NULL);
	number[0] = '-';
	number[1] = '2';
	number[2] = '1';
	number[3] = '4';
	number[4] = '7';
	number[5] = '4';
	number[6] = '8';
	number[7] = '3';
	number[8] = '6';
	number[9] = '4';
	number[10] = '8';
	number[11] = '\0';
	return (number);
}

char			*ft_itoa(int n)
{
	char	*number;
	int		pow;
	int		i;
	int		negative;

	if (n == -2147483648)
		return (exception());
	pow = 1;
	negative = (n < 0) ? -1 : 1;
	n *= negative;
	i = (negative == -1) ? 1 : 0;
	while (pow <= n / 10 && (i += 1))
		pow *= 10;
	if ((number = (char *)malloc(sizeof(*number) * (i + 2))) == NULL)
		return (NULL);
	i = (negative == -1) ? 1 : 0;
	number[0] = '-';
	while (pow > 0)
	{
		number[i++] = (n / pow) + 48;
		n = n % pow;
		pow /= 10;
	}
	number[i] = '\0';
	return (number);
}
