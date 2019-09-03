/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:10:21 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 21:49:57 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_o(t_printf *p, unsigned long o)
{
	int		total;

	p->a.sign = (p->a.p & HASH && o != 0) ? 1 : 0;
	p->a.zeros = MAX(p->a.precision - (int)ft_strlen(p->a.arg) - p->a.sign, 0);
	p->a.zeros += p->a.sign;
	p->a.str = (int)ft_strlen(p->a.arg);
	p->a.space = MAX(p->a.width - ((int)ft_strlen(p->a.arg) + p->a.zeros), 0);
	total = p->a.zeros + p->a.str + p->a.space;
	if (p->a.p & HASH && o == 0 && p->a.precision == 0 && ++total)
		write(1, "0", 1);
	while (!(p->a.p & MINUS) &&
			(!(p->a.p & ZERO) || p->a.precision != -1) && p->a.space--)
		write(1, " ", 1);
	while (0 < p->a.zeros--)
		write(1, "0", 1);
	while (p->a.p & ZERO && !(p->a.p & MINUS) && 0 < p->a.space--)
		write(1, "0", 1);
	write(1, p->a.arg, ft_strlen(p->a.arg));
	while (p->a.p & MINUS && p->a.space--)
		write(1, " ", 1);
	free(p->a.arg);
	return (total);
}

int		speci_o(t_printf *p)
{
	unsigned long long	o;

	o = 0;
	if (p->a.p & Z)
		o = (size_t)(va_arg(p->ap, size_t));
	else if (p->a.p & J)
		o = (uintmax_t)(va_arg(p->ap, uintmax_t));
	else if (p->a.p & LL)
		o = (unsigned long long)(va_arg(p->ap, unsigned long long));
	else if (p->a.p & L)
		o = (unsigned long)(va_arg(p->ap, unsigned long));
	else if (p->a.p & H)
		o = (unsigned short)(va_arg(p->ap, unsigned int));
	else if (p->a.p & HH)
		o = (unsigned char)(va_arg(p->ap, unsigned int));
	else
		o = (unsigned int)(va_arg(p->ap, unsigned int));
	p->a.arg = uitoa_printf(o, p, 8, "01234567");
	return (put_o(p, o));
}
