/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:12:02 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 23:18:09 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_u(t_printf *p, unsigned long u)
{
	int		total;

	p->a.sign = u - u;
	p->a.zeros = MAX(p->a.precision - (int)ft_strlen(p->a.arg), 0);
	p->a.space = MAX(p->a.width - p->a.str - p->a.zeros - p->a.sign, 0);
	total = p->a.zeros + p->a.str + p->a.space + p->a.sign;
	while (!(p->a.p & MINUS) &&
			(!(p->a.p & ZERO) || p->a.precision != -1) && p->a.space--)
		write(1, " ", 1);
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

int		speci_u(t_printf *p)
{
	unsigned long long	u;

	u = 0;
	if (p->a.p & Z)
		u = (size_t)(va_arg(p->ap, size_t));
	else if (p->a.p & J)
		u = (uintmax_t)(va_arg(p->ap, uintmax_t));
	else if (p->a.p & LL)
		u = (unsigned long long)(va_arg(p->ap, unsigned long long));
	else if (p->a.p & L)
		u = (unsigned long)(va_arg(p->ap, unsigned long));
	else if (p->a.p & H)
		u = (unsigned short)(va_arg(p->ap, unsigned int));
	else if (p->a.p & HH)
		u = (unsigned char)(va_arg(p->ap, unsigned int));
	else
		u = (unsigned int)(va_arg(p->ap, unsigned int));
	p->a.arg = uitoa_printf(u, p, 10, "0123456789");
	p->a.str = (int)ft_strlen(p->a.arg);
	return (put_u(p, u));
}
