/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:30:37 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/20 16:24:43 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*itoa_printf(intmax_t n, t_printf *p)
{
	char		*number;
	intmax_t	tmp;
	int			i;

	i = 0;
	tmp = 1;
	p->a.neg = n < 0 ? 1 : 0;
	if (n == 0 && p->a.precision == 0)
		return (ft_strdup(""));
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("9223372036854775808"));
	n = ABS(n);
	while (tmp <= n / 10 && ++i)
		tmp *= 10;
	if ((number = malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (tmp > 0)
	{
		number[i++] = (n / tmp) + 48;
		n = n % tmp;
		tmp /= 10;
	}
	number[i] = '\0';
	return (number);
}

char	*uitoa_printf(uintmax_t n, t_printf *p, int b, char *base)
{
	char		*number;
	uintmax_t	tmp;
	int			i;

	i = 0;
	tmp = 1;
	number = NULL;
	if (n == 0 && p->a.precision == 0)
		return (ft_strdup(""));
	while (tmp <= n / b && ++i)
		tmp *= b;
	if ((number = malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (tmp > 0)
	{
		number[i++] = base[n / tmp];
		n = n % tmp;
		tmp /= b;
	}
	number[i] = '\0';
	return (number);
}

void	fill_ftoa(char *number, long long inte, long long deci, t_printf *p)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = 1;
	while (tmp <= inte / 10)
		tmp *= 10;
	while (tmp != 0)
	{
		number[i++] = (inte / tmp) + 48;
		inte %= tmp;
		tmp /= 10;
	}
	tmp = ft_power(10, p->a.precision - 1);
	if (tmp > 0 || p->a.p & HASH)
		number[i++] = '.';
	while (tmp != 0)
	{
		number[i++] = (deci / tmp) + 48;
		deci %= tmp;
		tmp /= 10;
	}
	number[i] = '\0';
}

char	*ftoa_printf(long double n, t_printf *p)
{
	char		*number;
	long long	tmp;
	int			i;
	long long	integer;
	long long	decimal;

	i = 0;
	tmp = 1;
	p->a.neg = n < 0 ? 1 : 0;
	if (n == 0.0 && p->a.precision == 0)
		return (ft_strdup(""));
	n = ABS(n);
	integer = (long long)n;
	decimal = (n - (long double)integer) * ft_power(10, p->a.precision + 1);
	decimal = (decimal + ((decimal % 10 >= 5) ? 1 : 0)) / 10;
	while (tmp <= integer / 10 && ++i)
		tmp *= 10;
	if ((number = malloc(i + p->a.precision + 2)) == NULL)
		return (NULL);
	fill_ftoa(number, integer, decimal, p);
	return (number);
}
