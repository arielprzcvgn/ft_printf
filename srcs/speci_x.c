/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:12:32 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/14 21:15:47 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_x(t_printf *p, unsigned long x)
{
	int		total;

	p->a.sign = (p->a.p & HASH && x != 0) ? 2 : 0;
	p->a.zeros = MAX(p->a.precision - (int)ft_strlen(p->a.arg), 0);
	p->a.str = (int)ft_strlen(p->a.arg);
	p->a.space = MAX(p->a.width - p->a.str - p->a.zeros - p->a.sign, 0);
	total = p->a.zeros + p->a.str + p->a.space + p->a.sign;
	while (!(p->a.p & MINUS) &&
			(!(p->a.p & ZERO) || p->a.precision != -1) && p->a.space--)
		write(1, " ", 1);
	if (p->a.sign && !(p->a.p & HASH0))
		write(1, "0x", 2);
	else if (p->a.sign)
		write(1, "0X", 2);
	while (p->a.zeros--)
		write(1, "0", 1);
	while (p->a.p & ZERO && !(p->a.p & MINUS) && 0 < p->a.space--)
		write(1, "0", 1);
	write(1, p->a.arg, ft_strlen(p->a.arg));
	while (p->a.p & MINUS && p->a.space--)
		write(1, " ", 1);
	free(p->a.arg);
	return (total);
}

int		speci_x(t_printf *p)
{
	unsigned long long	x;

	x = 0;
	if (p->a.p & HH)
		x = (unsigned char)(va_arg(p->ap, unsigned int));
	else if (p->a.p & H)
		x = (unsigned short)(va_arg(p->ap, unsigned int));
	else if (p->a.p & L)
		x = (unsigned long)(va_arg(p->ap, unsigned long));
	else if (p->a.p & LL)
		x = (unsigned long long)(va_arg(p->ap, unsigned long long));
	else if (p->a.p & J)
		x = (uintmax_t)(va_arg(p->ap, uintmax_t));
	else if (p->a.p & Z)
		x = (size_t)(va_arg(p->ap, size_t));
	else
		x = (unsigned int)(va_arg(p->ap, unsigned int));
	if (!(p->a.p & HASH0))
		p->a.arg = uitoa_printf(x, p, 16, "0123456789abcdef");
	else if (p->a.p & HASH0)
		p->a.arg = uitoa_printf(x, p, 16, "0123456789ABCDEF");
	return (put_x(p, x));
}
