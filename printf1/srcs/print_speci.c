/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_speci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:01:40 by ariperez          #+#    #+#             */
/*   Updated: 2019/03/28 14:58:34 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		speci_c_s(int spec, char *s, t_param *par)
{
	char	*cpy;

	cpy = ft_strdup(s);
	if (spec == 1)
	{
		while (par->flags.minus && ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(cpy, " ", 1, 0);
		while (!par->flags.zero && ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(" ", cpy, 0, 1);
		while (par->flags.zero && ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree("0", cpy, 0, 1);
	}
	else if (spec == 2)
	{
		if (cpy && par->precision != -1 && (int)ft_strlen(cpy) > par->precision)
			*(cpy + par->precision) = '\0';
		while (cpy && par->flags.minus && ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(cpy, " ", 1, 0);
		while (cpy && !par->flags.minus && ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(" ", cpy, 0, 1);
		if (!cpy)
			cpy = "(null)";
	}
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}

int		speci_p(void *p, t_param *par)
{
	char	*cpy;

	cpy = ft_strdup(ft_ulltoa((unsigned long long)p));
	cpy = ft_convert_base(cpy, "0123456789", "0123456789abcdef");
	while (par->precision != -1 && (int)ft_strlen(cpy) < par->precision)
		cpy = ft_strjoinfree("0", cpy, 0, 1);
	cpy = ft_strjoinfree("0x", cpy, 0, 1);
	while (par->flags.minus && ft_strlen(cpy) < par->width)
		cpy = ft_strjoinfree(cpy, " ", 1, 0);
	while (!par->flags.minus && ft_strlen(cpy) < par->width)
		cpy = ft_strjoinfree(" ", cpy, 0, 1);
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}
