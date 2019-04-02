/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:09:22 by ariperez          #+#    #+#             */
/*   Updated: 2019/03/29 16:37:22 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int		ft_putdiouxx(char *str, t_param *par)
{
	int		ps;
	char	*s;

	s = ft_strdup(str);
	ps = 0;
	if (par->flags.plus == 2 || par->flags.space == 2 || par->flags.hash == 12)
		ps = 1;
	if (par->flags.hash == 13 || par->flags.hash == 14)
		ps = 2;
	while (par->precision != -1 && (int)ft_strlen(s) < par->precision)
		s = ft_strjoinfree("0", s, 0, 1);
	while (par->flags.minus && ft_strlen(s) < par->width - ps)
		s = ft_strjoinfree(s, " ", 1, 0);
	while (!par->flags.minus && par->flags.zero && ft_strlen(s) < par->width - ps)
		s = ft_strjoinfree("0", s, 0, 1);
	if (par->flags.plus == 2 && ft_atoi(s) >= 0)
		s = ft_strjoinfree("+", s, 0, 1);
	else if (par->flags.space == 2 && ft_atoi(s) >= 0)
		s = ft_strjoinfree(" ", s, 0, 1);
	if (par->flags.hash == 12 && *str != '\0')
		s = ft_strjoinfree("0", s, 0, 1);
	if (par->flags.hash == 13 && *str != '\0')
		s = ft_strjoinfree("0x", s, 0, 1);
	if (par->flags.hash == 14 && *str != '\0')
		s = ft_strjoinfree("0X", s, 0, 1);
	while (!par->flags.minus && ft_strlen(s) < par->width)
		s = ft_strjoinfree(" ", s, 0, 1);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

char	*exception(void)
{
	char	*number;

	if ((number = (char *)malloc(sizeof(*number) * 21)) == NULL)
		return (NULL);
	number = "-9223372036854775808";
	return (number);
}

char	*ft_lltoa(long long n)
{
	char		*number;
	long long	pow;
	int			i;
	int			negative;

	if (n == -92233720)
		return (exception());
	pow = 1;
	negative = (n < 0) ? -1 : 1;
	n *= negative;
	i = (negative == -1) ? 1 : 0;
	while (pow <= (n / 10) && (i += 1))
		pow *= 10;
	if ((number = (char *)malloc(i + 2)) == NULL)
		return (NULL);
	i = (negative == -1) ? 1 : 0;
	number[0] = '-';
	while (pow > 0)
	{
		number[i++] = (n / pow) + 48;
		n = n % pow;
		pow /= 10;
	}
	number[i] = '\0';
	return (number);
}

char	*ft_ulltoa(unsigned long long n)
{
	char				*number;
	unsigned long long	pow;
	int					i;

	pow = 1;
	i = 0;
	while (pow <= (n / 10) && (i += 1))
		pow *= 10;
	if ((number = (char *)malloc(i + 2)) == NULL)
		return (NULL);
	i = 0;
	while (pow > 0)
	{
		number[i++] = (n / pow) + 48;
		n = n % pow;
		pow /= 10;
	}
	number[i] = '\0';
	return (number);
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
	if (d_i == 0 && par->precision == 0)
		return (0);
	return (ft_putdiouxx(ft_lltoa((long long)d_i), par));
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
	if (par->flags.hash == 12 || par->flags.hash == 2)
		str = ft_convert_base(str, base(str), "01234567");
	if (par->flags.hash == 13 || par->flags.hash == 3)
		str = ft_convert_base(str, base(str), "0123456789abcdef");
	if (par->flags.hash == 14 || par->flags.hash == 4)
		str = ft_convert_base(str, base(str), "0123456789ABCDEF");
	if (o_u_x == 0 && par->precision == 0)
		str = ft_strdup("");
	return (ft_putdiouxx(str, par));
}

char	*specifier(char *str, va_list ap, t_param *par)
{
	if ((*str == 'd' || *str == 'i') && ++par->flags.plus && ++par->flags.space)
		par->ret += speci_d_i(ap, par);
	else if (*str == 'u')
		par->ret += speci_o_u_x(ap, par);
	else if (*str == 'o' && (par->flags.hash += 2))
		par->ret += speci_o_u_x(ap, par);
	else if (*str == 'x' && (par->flags.hash += 3))
		par->ret += speci_o_u_x(ap, par);
	else if (*str == 'X' && (par->flags.hash += 4))
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
	ft_printf("%llX", 9223372036854775807);
	return (0);
}*/
