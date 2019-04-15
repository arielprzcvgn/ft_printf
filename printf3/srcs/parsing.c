/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:20:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/15 16:42:30 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*length(t_printf *p)
{
	if (*p.format == 'h' && p.format++)
		p->p |= (*p.format++ == 'h') ? HH : H;
	else if (*p.format == 'l' && p.format++)
		p->p |= (*p.format++ == 'L') ? LL : L;
	else if (*p.format == 'j' && p.format++)
		p->p |= J;
	else if (*p.format == 'z' && p.format++)
		p->p |= Z;
	else if (*p.format == 'L' && p.format++)
		p->p |= LLL;
	return (specifier(p));
}

char	*precision(t_printf *p)
{
	if (*p.format == '.' && p.format++)
	{
		par->precision = 0;
		while ('0' <= *p.format && *p.format <= '9')
		{
			par->precision *= 10;
			par->precision += *p.format - 48;
			p.format++;
		}
		if (*p.format == '*' && p.format++)
			par->precision = va_arg(p.ap, int);
	}
	return (length(p));
}

char	*width(t_printf *p)
{
	while ('0' <= *p.format && *p.format <= '9')
	{
		par->width *= 10;
		par->width += *p.format - 48;
		p.format++;
	}
	if (*p.format == '*' && p.format++)
		par->width = va_arg(p.ap, int);
	return (precision(p));
}

char	*flags(t_printf *p)
{
	if (*p.format == '-' && p.format++)
		p->p |= MINUS;
	else if (*p.format == '0' && p.format++)
		p->p |= ZERO;
	else if (*p.format == '+' && p.format++)
		p->p |= PLUS;
	else if (*p.format == ' ' && p.format++)
		p->p |= SPACE;
	else if (*p.format == '#' && p.format++)
		p->p |= HASH0 | HASH1;
	else
		return (width(p));
	return (flags(p));
}
