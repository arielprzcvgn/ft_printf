/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:20:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 22:55:50 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	precision(t_printf *p)
{
	p->format++;
	p->a.precision = 0;
	while ('0' <= *p->format && *p->format <= '9')
	{
		p->a.precision *= 10;
		p->a.precision += *p->format - 48;
		p->format++;
	}
	if (*p->format == '*' && p->format++)
	{
		p->a.precision = va_arg(p->ap, int);
		if (p->a.precision < 0)
			p->a.precision = -1;
	}
}

void	width(t_printf *p)
{
	p->a.width = 0;
	while ('0' <= *p->format && *p->format <= '9')
	{
		p->a.width *= 10;
		p->a.width += *p->format - 48;
		p->format++;
	}
	if (*p->format == '*' && p->format++)
	{
		p->a.width = va_arg(p->ap, int);
		if (p->a.width < 0)
		{
			p->a.width *= -1;
			p->a.p |= MINUS;
		}
	}
}

int		ft_strchrpos(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

char	*parse(t_printf *p)
{
	int		i;

	p->a.precision = -1;
	while ((i = ft_strchrpos("-0+ ##'#hhlljzL.123456789*", *p->format)) > -1
			&& *p->format)
	{
		if (*p->format == 48 && 48 < *(p->format - 1) && *(p->format - 1) <= 57)
			i = -1;
		else if (*p->format == '.')
			precision(p);
		else if (15 <= i)
			width(p);
		else if (*p->format == 'l' && *(p->format + 1) == 'l' && (i++))
			p->format++;
		else if (*p->format == 'h' && *(p->format + 1) == 'h' && (i++))
			p->format++;
		if (0 <= i && i <= 14 && (p->a.p |= 1 << i))
			p->format++;
	}
	return (specifier(p));
}
