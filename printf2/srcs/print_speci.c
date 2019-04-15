/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_speci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:01:40 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/09 16:58:34 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		speci_c_s(int spec, char *s, t_param *par)
{
	char	*cpy;

	cpy = ft_strdup(s);
	if (spec == 1)
	{
		free(s);
		while (par->minus == 2 && (int)ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(cpy, " ", 1, 0);
		while (!par->minus && (int)ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(" ", cpy, 0, 1);
		while (par->minus == 1 && (int)ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree("0", cpy, 0, 1);
	}
	else if (spec == 2)
	{
		if (cpy && par->precision != -1 && (int)ft_strlen(cpy) > par->precision)
			*(cpy + par->precision) = '\0';
		while (cpy && par->minus && (int)ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(cpy, " ", 1, 0);
		while (cpy && !par->minus && (int)ft_strlen(cpy) < par->width)
			cpy = ft_strjoinfree(" ", cpy, 0, 1);
		if (!cpy)
			cpy = ft_strdup("(null)");
	}
	ft_putstr(cpy);
	spec = ft_strlen(cpy);
	free(cpy);
	return (spec);
}

int		speci_p(void *p, t_param *par)
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
