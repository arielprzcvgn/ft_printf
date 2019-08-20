/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:07:57 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/14 21:45:59 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_d_i(t_printf *p)
{
	int		total;

	p->a.sign = (p->a.p & PLUS || p->a.p & SPACE || p->a.neg == 1) ? 1 : 0;
	p->a.zeros = MAX(p->a.precision - (int)ft_strlen(p->a.arg), 0);
	p->a.str = (int)ft_strlen(p->a.arg);
	p->a.space = MAX(p->a.width - p->a.str - p->a.zeros - p->a.sign, 0);
	total = p->a.sign + p->a.zeros + p->a.str + p->a.space;
	while (!(p->a.p & MINUS) &&
			(!(p->a.p & ZERO) || p->a.precision != -1) && 0 < p->a.space--)
		write(1, " ", 1);
	if (p->a.neg == 1)
		write(1, "-", 1);
	else if (p->a.p & PLUS)
		write(1, "+", 1);
	else if (p->a.p & SPACE)
		write(1, " ", 1);
	while (p->a.zeros--)
		write(1, "0", 1);
	while (p->a.p & ZERO && !(p->a.p & MINUS) && 0 < p->a.space--)
		write(1, "0", 1);
	write(1, p->a.arg, ft_strlen(p->a.arg));
	while (p->a.p & MINUS && 0 < p->a.space--)
		write(1, " ", 1);
	free(p->a.arg);
	return (total);
}

int		speci_d_i(t_printf *p)
{
	long long	d_i;

	d_i = 0;
	if (p->a.p & HH)
		d_i = (signed char)(va_arg(p->ap, int));
	else if (p->a.p & H)
		d_i = (short)(va_arg(p->ap, int));
	else if (p->a.p & L)
		d_i = (long)(va_arg(p->ap, long));
	else if (p->a.p & LL)
		d_i = (long long)(va_arg(p->ap, long long));
	else if (p->a.p & J)
		d_i = (intmax_t)(va_arg(p->ap, intmax_t));
	else if (p->a.p & Z)
		d_i = (size_t)(va_arg(p->ap, size_t));
	else
		d_i = (int)(va_arg(p->ap, int));
	p->a.arg = itoa_printf(d_i, p);
	return (put_d_i(p));
}
