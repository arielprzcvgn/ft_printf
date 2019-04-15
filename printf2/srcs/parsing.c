/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:20:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/09 16:42:37 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*length(char *str, va_list ap, t_param *par)
{
	if (*str == 'h' && str++)
	{
		if (*str == 'h' && str++)
			par->length = 1;
		else
			par->length = 2;
	}
	else if (*str == 'l' && str++)
	{
		if (*str == 'l' && str++)
			par->length = 4;
		else
			par->length = 3;
	}
	else if (*str == 'L' && str++)
		par->length = 5;
	return (specifier(str, ap, par));
}

char	*precision(char *str, va_list ap, t_param *par)
{
	if (*str == '.' && str++)
	{
		par->precision = 0;
		while ('0' <= *str && *str <= '9')
		{
			par->precision *= 10;
			par->precision += *str - 48;
			str = str + 1;
		}
		if (*str == '*' && str++)
			par->precision = va_arg(ap, int);
	}
	return (length(str, ap, par));
}

char	*width(char *str, va_list ap, t_param *par)
{
	while ('0' <= *str && *str <= '9')
	{
		par->width *= 10;
		par->width += *str - 48;
		str = str + 1;
	}
	if (*str == '*' && str++)
		par->width = va_arg(ap, int);
	return (precision(str, ap, par));
}

char	*flags(char *str, va_list ap, t_param *par)
{
	if (*str == '-' && str++)
		par->minus = 2;
	else if (*str == '0' && str++)
		par->minus = (par->minus == 2) ? 2 : 1;
	else if (*str == '+' && str++)
		par->sign = 2;
	else if (*str == ' ' && str++)
		par->sign = (par->sign == 2) ? 2 : 1;
	else if (*str == '#' && str++)
		par->hash = 10;
	else
		return (width(str, ap, par));
	return (flags(str, ap, par));
}

t_param	initialize(t_param par)
{
	par.minus = 0;
	par.sign = 0;
	par.hash = 0;
	par.width = 0;
	par.precision = -1;
	par.length = 0;
	par.ret = 0;
	return (par);
}
