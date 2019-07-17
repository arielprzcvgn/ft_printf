/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:20:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/07/12 16:00:40 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*length(t_printf *p)
{
	if (*p->format == 'h' && p->format++)
	{
		if (*p->format == 'h' && p->format++)
			p->a.p |= HH;
		else
			p->a.p |= H;
	}
	else if (*p->format == 'l' && p->format++)
	{
		if (*p->format == 'l' && p->format++)
			p->a.p |= LL;
		else
			p->a.p |= L;
	}
	else if (*p->format == 'j' && p->format++)
		p->a.p |= J;
	else if (*p->format == 'z' && p->format++)
		p->a.p |= Z;
	else if (*p->format == 'L' && p->format++)
		p->a.p |= LLL;
	return (specifier(p));
}

char	*precision(t_printf *p)
{
	if (*p->format == '.' && p->format++)
	{
		p->a.precision = 0;
		while ('0' <= *p->format && *p->format <= '9')
		{
			p->a.precision *= 10;
			p->a.precision += *p->format - 48;
			p->format++;
		}
		if (*p->format == '*' && p->format++)
			p->a.precision = va_arg(p->ap, int);
	}
	else
		p->a.precision = -1;
	return (length(p));
}

char	*width(t_printf *p)
{
	while ('0' <= *p->format && *p->format <= '9')
	{
		p->a.width *= 10;
		p->a.width += *p->format - 48;
		p->format++;
	}
	if (*p->format == '*' && p->format++)
		p->a.width = va_arg(p->ap, int);
	return (precision(p));
}

char	*flags(t_printf *p)
{
	if (*p->format == '-' && p->format++)
		p->a.p |= MINUS;
	else if (*p->format == '0' && p->format++)
		p->a.p |= ZERO;
	else if (*p->format == '+' && p->format++)
		p->a.p |= PLUS;
	else if (*p->format == ' ' && p->format++)
		p->a.p |= SPACE;
	else if (*p->format == '#' && p->format++)
		p->a.p |= HASH;
	else
		return (width(p));
	return (flags(p));
}
