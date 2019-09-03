/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:15:24 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 23:33:26 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

double	arrondi(long double n, t_printf *p)
{
	long double i;
	long double arr;

	i = 0;
	arr = 1.0;
	while (i++ < p->a.precision)
		n = (n * 10) - (int)(n * 10);
	while ((n < 0 ? -1 : 1) * n * 10 >= 5 && --i)
		arr /= 10.0;
	if ((n < 0 ? -1 : 1) * n * 10 < 5)
		return (0.0);
	return ((n < 0 ? -1 : 1) * arr);
}

int		speci_f(t_printf *p)
{
	long double		f;

	f = 0;
	if (p->a.p & LLL)
		f = (long double)(va_arg(p->ap, long double));
	else
		f = (double)(va_arg(p->ap, double));
	if (p->a.precision == -1)
		p->a.precision = 6;
	if (f == f)
		p->a.str = ftoa_printf(f, p);
	else
		ft_memcpy(p->buffer + p->c, "nan", (p->a.str = 3));
	p->a.p & APOS ? apostrophe(p) : 0;
	p->a.space = MAX(p->a.width - p->a.str, 0);
	if (p->a.p & MINUS)
		ft_memset(p->buffer + p->c + p->a.str, ' ', p->a.space);
	else
	{
		ft_memmove(p->buffer + p->c + p->a.space, p->buffer + p->c, p->a.str);
		(p->a.p & ZERO && f == f) ? ft_memset(p->buffer + p->c + p->a.sign, '0',
				p->a.space) : ft_memset(p->buffer + p->c, ' ', p->a.space);
	}
	write(1, p->buffer, ft_strlen(p->buffer));
	return (p->a.str + p->a.space);
}

int		ftoa_printf(long double n, t_printf *p)
{
	int		i;
	char	*number;

	i = (p->a.p & PLUS) ? '+' : ' ';
	i = (n < 0) ? '-' : i;
	p->a.sign = (p->a.p & PLUS || p->a.p & SPACE || n < 0) ? 1 : 0;
	ft_memset(p->buffer + p->c, i, p->a.sign);
	number = ft_ulltoa((unsigned long long)ABS(n));
	i = p->a.sign + ft_strlen(number);
	ft_memcpy(p->buffer + p->c + p->a.sign, number, i - p->a.sign);
	n += (n < 0 ? 1 : -1) * (long double)(unsigned long)(ABS(n));
	n += (p->a.precision > 10) ? 0 : arrondi(n, p);
	if (p->a.p & HASH || p->a.precision > 0)
		p->buffer[p->c + i++] = '.';
	while (p->a.precision--)
	{
		n *= 10.0;
		n += (p->a.precision == 10) ? arrondi(n, p) : 0;
		p->buffer[p->c + i++] = (((n < 0) ? -1 : 1) * (int)n) + 48;
		n -= (int)n;
	}
	p->buffer[p->c + i] = '\0';
	free(number);
	return (i);
}
