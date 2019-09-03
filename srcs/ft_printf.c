/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:09:22 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 22:18:34 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*specifier(t_printf *p)
{
	('A' <= *p->format && *p->format < 'X') ? p->a.p |= L : 0;
	if (*p->format == 'd' || *p->format == 'i' || *p->format == 'D')
		p->printed += speci_d_i(p);
	else if (*p->format == 'u' || *p->format == 'U')
		p->printed += speci_u(p);
	else if (*p->format == 'o' || *p->format == 'O')
		p->printed += speci_o(p);
	else if (*p->format == 'x')
		p->printed += speci_x(p);
	else if (*p->format == 'X' && (p->a.p |= HASH0))
		p->printed += speci_x(p);
	else if (*p->format == 'f')
		p->printed += speci_f(p);
	else if (*p->format == 'c')
		p->printed += speci_c(p, 0);
	else if (*p->format == 's')
		p->printed += speci_s(va_arg(p->ap, char*), p);
	else if (*p->format == 'p')
		p->printed += speci_p(va_arg(p->ap, void*), p);
	else if (*p->format == '%')
		p->printed += speci_c(p, 1);
	else
		return (p->format - 1);
	return (p->format);
}

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_memset(&p, 0, sizeof(p));
	if ((p.buffer = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	p.format = (char*)format;
	va_start(p.ap, format);
	while (*p.format)
	{
		if (*p.format == '%' && *(p.format + 1) && p.format++)
			p.format = parse(&p) + 1;
		else if (*p.format == '%' && *(p.format + 1) == '\0')
			p.format++;
		else if (*p.format)
		{
			ft_putchar(*p.format);
			p.printed++;
			p.format++;
		}
		ft_memset(&p.a, 0, sizeof(p.a));
	}
	va_end(p.ap);
	free(p.buffer);
	return (p.printed);
}
