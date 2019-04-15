/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:30:37 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/09 16:59:38 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*base(char *nbr)
{
	if (nbr[0] == '0')
	{
		if (nbr[1] == 'b')
			return ("01");
		else if (nbr[1] == 'x')
			return ("0123456789abcdef");
		else
			return ("01234567");
	}
	return ("0123456789");
}

char	*chartostring(char c)
{
	char	*string;

	string = malloc(2);
	*string = c;
	*(string + 1) = '\0';
	return (string);
}

char	*ft_lltoa(long long n)
{
	char		*number;
	long long	pow;
	int			i;
	int			negative;

	pow = 1;
	negative = (n < 0) ? -1 : 1;
	n *= negative;
	i = (negative == -1) ? 1 : 0;
	while (pow <= (n / 10) && (i += 1))
		pow *= 10;
	if ((number = (char *)malloc(i + 2)) == NULL)
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

char	*ft_ulltoa(unsigned long long n)
{
	char				*number;
	unsigned long long	pow;
	int					i;

	pow = 1;
	i = 0;
	while (pow <= (n / 10) && (i += 1))
		pow *= 10;
	if ((number = (char *)malloc(i + 2)) == NULL)
		return (NULL);
	i = 0;
	while (pow > 0)
	{
		number[i++] = (n / pow) + 48;
		n = n % pow;
		pow /= 10;
	}
	number[i] = '\0';
	return (number);
}
