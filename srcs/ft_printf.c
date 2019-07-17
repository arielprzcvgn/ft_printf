/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:09:22 by ariperez          #+#    #+#             */
/*   Updated: 2019/07/17 21:20:08 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_d_i(t_printf *p)
{
	int		total;

	p->a.zeros = MAX(p->a.precision - (int)ft_strlen(p->a.arg), 0);
	p->a.str = (int)ft_strlen(p->a.arg);
	p->a.space = MAX((p->a.width - (p->a.str + p->a.zeros + (BOOL(p->a.sign)))), 0);
	total = (p->a.sign == 0 ? 0 : 1) + p->a.zeros + p->a.str + p->a.space;
	while (!(p->a.p & MINUS) && (!(p->a.p & ZERO) || p->a.precision != -1) && 0 < p->a.space--)
		write(1, " ", 1);
	if (p->a.sign == 3)
		write(1, "-", 1);
	else if (p->a.sign == 2)
		write(1, "+", 1);
	else if (p->a.sign == 1)
		write(1, " ", 1);
	while (p->a.zeros--)
		write(1, "0", 1);
	while (p->a.p & ZERO && 0 < p->a.space--)
		write(1, "0", 1);
	write(1, p->a.arg, ft_strlen(p->a.arg));
	while (p->a.p & MINUS && p->a.space--)
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
	else
		d_i = (int)(va_arg(p->ap, int));
	p->a.arg = ft_strdup(itoa_printf(d_i, p));
	return (put_d_i(p));
}

int		put_o_u_x(t_printf *p, unsigned long o_u_x)
{
	int		total;

	p->a.sign = (p->a.p & HASH1) ? 2 : (p->a.p & HASH0) ? 1 : 0;
	p->a.sign = (p->a.p & HASH && o_u_x != 0) ? p->a.sign : 0;
	p->a.zeros = MAX(p->a.precision - (int)ft_strlen(p->a.arg), 0);
	p->a.str = (int)ft_strlen(p->a.arg);
	p->a.space = MAX(p->a.width - ((int)ft_strlen(p->a.arg) + p->a.zeros + p->a.sign), 0);
	total = p->a.zeros + p->a.str + p->a.space + p->a.sign;
	while (!(p->a.p & MINUS) && (!(p->a.p & ZERO) || p->a.precision != -1) && p->a.space--)
		write(1, " ", 1);
	//if (p->a.p & HASH && p->a.p & HASH0 && !(p->a.p & HASH1))
	if (p->a.sign == 1)
		write(1, "0", 1);
	//else if (p->a.p & HASH && !(p->a.p & HASH0) && p->a.p & HASH1)
	else if (p->a.sign == 2 && !(p->a.p & HASH0))
		write(1, "0x", 2);
	//else if (p->a.p & HASH && p->a.p & HASH0 && p->a.p & HASH1)
	else if (p->a.sign == 2)
		write(1, "0X", 2);
	while (p->a.zeros--)
		write(1, "0", 1);
	while (p->a.p & ZERO && 0 < p->a.space--)
		write(1, "0", 1);
	write(1, p->a.arg, ft_strlen(p->a.arg));
	while (p->a.p & MINUS && p->a.space--)
		write(1, " ", 1);
	free(p->a.arg);
	return (total);
}

int		speci_o_u_x(t_printf *p)
{
	unsigned long long	o_u_x;

	o_u_x = 0;
	if (p->a.p & HH)
		o_u_x = (unsigned char)(va_arg(p->ap, unsigned int));
	else if (p->a.p & H)
		o_u_x = (unsigned short)(va_arg(p->ap, unsigned int));
	else if (p->a.p & L)
		o_u_x = (unsigned long)(va_arg(p->ap, unsigned long));
	else if (p->a.p & LL)
		o_u_x = (unsigned long long)(va_arg(p->ap, unsigned long long));
	else
		o_u_x = (unsigned int)(va_arg(p->ap, unsigned int));
	p->a.arg = ft_strdup(uitoa_printf(o_u_x, p));
	if (p->a.p & HASH0 && !(p->a.p & HASH1) && *(p->a.arg))
		p->a.arg = ft_convert_base(p->a.arg, base(p->a.arg), "01234567");
	else if (!(p->a.p & HASH0) && p->a.p & HASH1 && *(p->a.arg))
		p->a.arg = ft_convert_base(p->a.arg, base(p->a.arg), "0123456789abcdef");
	else if (p->a.p & (HASH0 | HASH1) && *(p->a.arg))
		p->a.arg = ft_convert_base(p->a.arg, base(p->a.arg), "0123456789ABCDEF");
	return (put_o_u_x(p, o_u_x));
}

char	*specifier(t_printf *p)
{
	if (*p->format == 'd' || *p->format == 'i' || *p->format == 'D')
		p->printed += speci_d_i(p);
	else if (*p->format == 'u' || *p->format == 'U')
		p->printed += speci_o_u_x(p);
	else if ((*p->format == 'o' || *p->format == 'O') && 
			(p->a.p |= HASH0 | !HASH1))
		p->printed += speci_o_u_x(p);
	else if (*p->format == 'x' && (p->a.p |= !HASH0 | HASH1))
		p->printed += speci_o_u_x(p);
	else if (*p->format == 'X' && (p->a.p |= HASH0 | HASH1))
		p->printed += speci_o_u_x(p);
	else if (*p->format == 'c' || *p->format == 'C')
		p->printed += speci_c_s(1, chartostring(va_arg(p->ap, int)), p);
	else if (*p->format == 's')
		p->printed += speci_c_s(2, va_arg(p->ap, char*), p);
	else if (*p->format == 'p')
		p->printed += speci_p(va_arg(p->ap, void*), p);
	else if (*p->format == '%')
		p->printed += speci_c_s(1, chartostring('%'), p);
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
	ft_printf("\n%i\n", ft_printf("%#.0o", 0));
	return (0);
}*/
