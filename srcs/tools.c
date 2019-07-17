/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:30:37 by ariperez          #+#    #+#             */
/*   Updated: 2019/07/12 13:49:11 by ariperez         ###   ########.fr       */
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

char	*itoa_printf(intmax_t n, t_printf *p)
{
	char		*number;
	intmax_t	tmp;
	int			i;

	i = 0;
	tmp = 1;
	p->a.sign = (n < 0) ? 3 : (p->a.p & PLUS) ? 2 : (p->a.p & SPACE) ? 1 : 0;
	if (n == 0 && p->a.precision == 0)
		return ("");
	n = ABS(n);
	while (tmp * 10 <= n && ++i)
		tmp *= 10;
	if ((number = malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (tmp > 0)
	{
		*(number + i) = (n / tmp) + 48;
		n = n % tmp;
		tmp /= 10;
		i++;
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
