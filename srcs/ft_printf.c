/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:09:22 by ariperez          #+#    #+#             */
/*   Updated: 2019/07/19 16:49:16 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*specifier(t_printf *p)
{
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
	else if (*p->format == 'c' || *p->format == 'C')
		p->printed += speci_c(chartostring(va_arg(p->ap, int)), p);
	else if (*p->format == 's')
		p->printed += speci_s(va_arg(p->ap, char*), p);
	else if (*p->format == 'p')
		p->printed += speci_p(va_arg(p->ap, void*), p);
	else if (*p->format == '%')
		p->printed += speci_c(chartostring('%'), p);
	return (p->format);
}

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	p.format = (char*)format;
	va_start(p.ap, format);
	while (*p.format)
	{
		if (*p.format == '%' && p.format++)
			p.format = flags(&p) + 1;
		else if (*p.format)
		{
			ft_putchar(*p.format);
			p.printed++;
			p.format++;
		}
		ft_bzero(&p.a, sizeof(p.a));
	}
	va_end(p.ap);
	return (p.printed);
}
/*
int     main(void)
{
	ft_printf("\n%i\n", ft_printf("%#.o", 0));
	return (0);
}*/
