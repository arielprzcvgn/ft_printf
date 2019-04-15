/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_speci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:01:40 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/15 16:53:04 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		speci_c_s(int spec, char *cpy, t_printf *p)
{
	char	*s;

	s = ft_strdup(cpy);
	if (spec == 1)
	{
		while (par->minus == 2 && (int)ft_strlen(s) < par->width)
			s = ft_strjoinfree(s, " ", 1, 0);
		while (!par->minus && (int)ft_strlen(s) < par->width)
			s = ft_strjoinfree(" ", s, 0, 1);
		while (par->minus == 1 && (int)ft_strlen(s) < par->width)
			s = ft_strjoinfree("0", s, 0, 1);
	}
	else if (spec == 2)
	{
		if (s && par->precision != -1 && (int)ft_strlen(s) > par->precision)
			*(s + par->precision) = '\0';
		while (s && par->minus && (int)ft_strlen(s) < par->width)
			s = ft_strjoinfree(s, " ", 1, 0);
		while (s && !par->minus && (int)ft_strlen(s) < par->width)
			s = ft_strjoinfree(" ", s, 0, 1);
		if (!s)
			s = ft_strdup("(null)");
	}
	ft_putstr(s);
	spec = ft_strlen(s);
	free(s);
	return (spec);
}

int		speci_p(void *p, t_printf *p)
{
	char	*cpy;
	char    *cpycpy;
	int		total;

	cpycpy = ft_ulltoa((unsigned long long)p);
	cpy = ft_convert_base(cpycpy, "0123456789", "0123456789abcdef");
	free(cpycpy);
	while (par->precision != -1 && (int)ft_strlen(cpy) < par->precision)
		cpy = ft_strjoinfree("0", cpy, 0, 1);
	cpy = ft_strjoinfree("0x", cpy, 0, 1);
	while (par->minus && (int)ft_strlen(cpy) < par->width)
		cpy = ft_strjoinfree(cpy, " ", 1, 0);
	while (!par->minus && (int)ft_strlen(cpy) < par->width)
		cpy = ft_strjoinfree(" ", cpy, 0, 1);
	ft_putstr(cpy);
	total = ft_strlen(cpy);
	free(cpy);
	return (total);
}
