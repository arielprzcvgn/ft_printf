/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:09:22 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/09 17:02:35 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int		put_d_i(char *str, t_param *par)
{
	int		total;

	par->arg.sign = par->sign;
	par->arg.zeros = MAX(par->precision - (int)ft_strlen(str), 0);
	par->arg.str = (int)ft_strlen(str);
	par->arg.space = MAX((par->width - ((int)ft_strlen(str) + par->arg.zeros +
						((par->arg.sign == 0) ? 0 : 1))), 0);
	total = ((par->arg.sign == 0) ? 0 : 1) + par->arg.zeros +
					par->arg.str + par->arg.space;
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
	write(1, str, ft_strlen(str));
	while (par->minus == 2 && par->arg.space--)
		write(1, " ", 1);
	free(str);
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

int		put_o_u_x(char *str, t_param *par)
{
	int		total;

	par->arg.sign = par->hash;
	par->arg.zeros = MAX(par->precision - (int)ft_strlen(str), 0);
	par->arg.str = (int)ft_strlen(str);
	par->arg.space = MAX(par->width - ((int)ft_strlen(str) + par->arg.zeros +
					((par->arg.sign % 10) % 3) * (par->arg.sign / 10)), 0);
	total = ((par->arg.sign % 10) % 3) * (par->arg.sign / 10) +
				par->arg.zeros + par->arg.str + par->arg.space;
	while (par->minus < 2 && par->precision >= 0 && par->arg.space--)
		write(1, " ", 1);
	if (par->hash == 11)
		write(1, "0", 1);
	else if (par->hash == 12)
		write(1, "0x", 2);
	else if (par->hash == 15)
		write(1, "0X", 2);
	while (par->arg.zeros--)
		write(1, "0", 1);
	while (par->minus == 1 && par->precision == -1 && par->arg.space--)
		write(1, "0", 1);
	write(1, str, ft_strlen(str));
	while (par->minus == 2 && par->arg.space--)
		write(1, " ", 1);
	free(str);
	return (total);
}

int		speci_o_u_x(va_list ap, t_param *par)
{
	unsigned long long	o_u_x;
	char				*str;

	o_u_x = 0;
	if (par->length == 0)
		o_u_x = (unsigned int)(va_arg(ap, unsigned int));
	else if (par->length == 1)
		o_u_x = (unsigned char)(va_arg(ap, unsigned int));
	else if (par->length == 2)
		o_u_x = (unsigned short)(va_arg(ap, unsigned int));
	else if (par->length == 3)
		o_u_x = (unsigned long)(va_arg(ap, unsigned long));
	else if (par->length == 4)
		o_u_x = (unsigned long long)(va_arg(ap, unsigned long long));
	str = ft_ulltoa((unsigned long long)o_u_x);
	if (par->hash % 10 == 1)
		str = ft_convert_base(str, base(str), "01234567");
	if (par->hash % 10 == 2)
		str = ft_convert_base(str, base(str), "0123456789abcdef");
	if (par->hash % 10 == 5)
		str = ft_convert_base(str, base(str), "0123456789ABCDEF");
	if (o_u_x == 0 && par->precision == 0 && !(par->hash = 0))
		str = ft_strdup("");
	return (put_o_u_x(str, par));
}

char	*specifier(char *str, va_list ap, t_param *par)
{
	if (*str == 'd' || *str == 'i')
		par->ret += speci_d_i(ap, par);
	else if (*str == 'u')
		par->ret += speci_o_u_x(ap, par);
	else if (*str == 'o' && (par->hash += 1))
		par->ret += speci_o_u_x(ap, par);
	else if (*str == 'x' && (par->hash += 2))
		par->ret += speci_o_u_x(ap, par);
	else if (*str == 'X' && (par->hash += 5))
		par->ret += speci_o_u_x(ap, par);
	else if (*str == 'c')
		par->ret += speci_c_s(1, chartostring(va_arg(ap, int)), par);
	else if (*str == 's')
		par->ret += speci_c_s(2, va_arg(ap, char*), par);
	else if (*str == 'p')
		par->ret += speci_p(va_arg(ap, void*), par);
	else if (*str == '%')
		par->ret += speci_c_s(1, chartostring('%'), par);
	return (str);
}

int		ft_printf(char *str, ...)
{
	va_list		ap;
	int			ret;
	t_param		par;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && str++)
		{
			par = initialize(par);
			str = flags(str, ap, &par) + 1;
			ret += par.ret;
		}
		else if (*str)
		{
			ft_putchar(*str);
			ret++;
			str++;
		}
	}
	va_end(ap);
	return (ret);
}
/*
int		main(void)
{
	ft_printf("%x", 42);
	//printf("\n%x", 42);
	return (0);
}*/
