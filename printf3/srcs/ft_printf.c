/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:09:22 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/15 21:05:33 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int		put_d_i(char *p.format, t_param *par)
{
	int		total;

	par->arg.sign = par->sign;
	par->arg.zeros = MAX(par->precision - (int)ft_p.formatlen(p.format), 0);
	par->arg.p.format = (int)ft_p.formatlen(p.format);
	par->arg.space = MAX((par->width - ((int)ft_p.formatlen(p.format) + par->arg.zeros +
						((par->arg.sign == 0) ? 0 : 1))), 0);
	total = ((par->arg.sign == 0) ? 0 : 1) + par->arg.zeros +
					par->arg.p.format + par->arg.space;
	while (par->minus < 2 && par->precision >= 0 && par->arg.space--)
		write(1, " ", 1);
	if (par->sign == 3)
		write(1, "-", 1);
	else if (par->sign == 2)
		write(1, "+", 1);
	else if (par->sign == 1)
		write(1, " ", 1);
	while (par->arg.zeros--)
		write(1, "0", 1);
	while (par->minus == 1 && par->precision == -1 && par->arg.space--)
		write(1, "0", 1);
	write(1, p.format, ft_p.formatlen(p.format));
	while (par->minus == 2 && par->arg.space--)
		write(1, " ", 1);
	free(p.format);
	return (total);
}

int		speci_d_i(va_list ap, t_param *par)
{
	long long	d_i;

	d_i = 0;
	if (par->length == 0)
		d_i = (int)(va_arg(ap, int));
	else if (par->length == 1)
		d_i = (signed char)(va_arg(ap, int));
	else if (par->length == 2)
		d_i = (short)(va_arg(ap, int));
	else if (par->length == 3)
		d_i = (long)(va_arg(ap, long));
	else if (par->length == 4)
		d_i = (long long)(va_arg(ap, long long));
	if (d_i < 0 && (par->sign = 3))
		d_i *= -1;
	if (d_i == 0 && par->precision == 0)
		return (put_d_i("", par));
	return (put_d_i(ft_lltoa((long long)d_i), par));
}

int		put_o_u_x(t_printf *p)
{
	int		total;

	par->sign = par->hash;
	par->zeros = MAX(par->precision - (int)ft_strlen(p.format), 0);
	par->str = (int)ft_strlen(p.format);
	par->space = MAX(par->width - ((int)ft_strlen(p.format) + par->arg.zeros +
					((par->arg.sign % 10) % 3) * (par->arg.sign / 10)), 0);
	total = ((par->arg.sign % 10) % 3) * (par->arg.sign / 10) +
				par->arg.zeros + par->arg.p.format + par->arg.space;
	while (par->minus < 2 && par->precision >= 0 && par->arg.space--)
		write(1, " ", 1);
	if (p->p & HASH0 && p->p & !HASH1)
		write(1, "0", 1);
	else if (p->p & !HASH0 && p->p & HASH1)
		write(1, "0x", 2);
	else if (p->p & HASH0 && p->p & HASH1)
		write(1, "0X", 2);
	while (par->zeros--)
		write(1, "0", 1);
	while (par->minus == 1 && par->precision == -1 && par->arg.space--)
		write(1, "0", 1);
	write(1, p.format, ft_p.formatlen(p.format));
	while (par->minus == 2 && par->arg.space--)
		write(1, " ", 1);
	free(p.format);
	return (total);
}

int		speci_o_u_x(va_list ap, t_param *par)
{
	unsigned long long	o_u_x;

	o_u_x = 0;
	if (p->p & HH)
		o_u_x = (unsigned char)(va_arg(ap, unsigned int));
	else if (p->p & H)
		o_u_x = (unsigned short)(va_arg(ap, unsigned int));
	else if (p->p & L)
		o_u_x = (unsigned long)(va_arg(ap, unsigned long));
	else if (p->p & LL)
		o_u_x = (unsigned long long)(va_arg(ap, unsigned long long));
	else
		o_u_x = (unsigned int)(va_arg(ap, unsigned int));
	p->format = ft_ulltoa((unsigned long long)o_u_x);
	if (p->p & HASH0 && p->p & !HASH1)
		p->format = ft_convert_base(p.format, base(p.format), "01234567");
	if (p->p & !HASH0 && p->p & HASH1)
		p->format = ft_convert_base(p.format, base(p.format), "0123456789abcdef");
	if (p->p & HASH0 && p->p & HASH1)
		p->format = ft_convert_base(p.format, base(p.format), "0123456789ABCDEF");
	if (o_u_x == 0 && par->precision == 0 && !(par->hash = 0))
		p->format = ft_strdup("");
	return (put_o_u_x(p));
}

char	*specifier(t_printf *p)
{
	if (*p.format == 'd' || *p.format == 'i')
		p->printed += speci_d_i(p);
	else if (*p.format == 'u')
		p->printed += speci_o_u_x(p);
	else if (*p.format == 'o' && p->p &= !HASH1)
		p->printed += speci_o_u_x(p);
	else if (*p.format == 'x' && p->p &= !HASH0)
		p->printed += speci_o_u_x(p);
	else if (*p.format == 'X')
		p->printed += speci_o_u_x(p);
	else if (*p.format == 'c')
		p->printed += speci_c_s(1, chartostring(va_arg(p->ap, int)), p);
	else if (*p.format == 's')
		p->printed += speci_c_s(2, va_arg(p->ap, char*), p);
	else if (*p.format == 'p')
		p->printed += speci_p(va_arg(ap, void*), par);
	else if (*p.format == '%')
		p->printed += speci_c_s(1, chartostring('%'), p);
	return (p.format);
}

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	p.format = (char*)format;
	p.ap = va_start(ap, p.format);
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
	}
	va_end(p.ap);
	return (p.printed);
}
/*
int		main(void)
{
	ft_printf("%x", 42);
	//printf("\n%x", 42);
	return (0);
}*/
