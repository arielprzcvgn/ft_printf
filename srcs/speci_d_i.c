/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:07:57 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 23:21:12 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_d_i(t_printf *p)
{
	int		i;

	i = 0;
	ft_memmove(p->buffer + p->a.sign + p->a.zeros,
			p->buffer + p->a.sign, p->a.str - p->a.sign);
	ft_memset(p->buffer + p->c + p->a.sign, '0', p->a.zeros);
	if (p->a.p & MINUS)
		ft_memset(p->buffer + p->a.str + p->a.zeros, ' ', p->a.space);
	else
	{
		ft_memmove(p->buffer + p->a.space, p->buffer, p->a.str + p->a.zeros);
		(!(p->a.p & ZERO) || p->a.precision != -1) ? ft_memset(p->buffer, ' ',
		p->a.space) : ft_memset(p->buffer + p->a.sign, '0', p->a.space);
	}
	write(1, p->buffer, p->a.zeros + p->a.str + p->a.space);
	return (p->a.zeros + p->a.str + p->a.space);
}

int		speci_d_i(t_printf *p)
{
	long long	d_i;

	d_i = 0;
	if (p->a.p & Z)
		d_i = (size_t)(va_arg(p->ap, size_t));
	else if (p->a.p & J)
		d_i = (intmax_t)(va_arg(p->ap, intmax_t));
	else if (p->a.p & LL)
		d_i = (long long)(va_arg(p->ap, long long));
	else if (p->a.p & L)
		d_i = (long)(va_arg(p->ap, long));
	else if (p->a.p & H)
		d_i = (short)(va_arg(p->ap, int));
	else if (p->a.p & HH)
		d_i = (signed char)(va_arg(p->ap, int));
	else
		d_i = (int)(va_arg(p->ap, int));
	p->a.str = itoa_printf(d_i, p);
	p->a.p & APOS ? apostrophe(p) : 0;
	p->a.zeros = MAX(p->a.precision - p->a.str + p->a.sign, 0);
	p->a.space = MAX(p->a.width - p->a.str - p->a.zeros, 0);
	return (put_d_i(p));
}
