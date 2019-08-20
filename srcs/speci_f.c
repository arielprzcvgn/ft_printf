/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:15:24 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/20 16:24:07 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_f(t_printf *p)
{
	int		total;

	p->a.sign = (p->a.p & PLUS || p->a.p & SPACE || p->a.neg == 1) ? 1 : 0;
	p->a.zeros = MAX(p->a.precision - (int)ft_strlen(p->a.arg), 0);
	p->a.str = (int)ft_strlen(p->a.arg);
	p->a.space = MAX(p->a.width - p->a.str - p->a.zeros - p->a.sign, 0);
	total = p->a.sign + p->a.zeros + p->a.str + p->a.space;
	while (!(p->a.p & MINUS) && !(p->a.p & ZERO) && 0 < p->a.space--)
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
	p->a.arg = ftoa_printf(f, p);
	return (put_f(p));
}
