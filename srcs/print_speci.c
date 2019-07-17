/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_speci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:01:40 by ariperez          #+#    #+#             */
/*   Updated: 2019/05/28 18:23:00 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		speci_c_s(int spec, char *cpy, t_printf *p)
{
	char	*s;

	s = ft_strdup(cpy);
	if (spec == 1)
	{
		while (p->a.p & MINUS && (int)ft_strlen(s) < p->a.width)
			s = ft_strjoinfree(s, " ", 1, 0);
		while (!(p->a.p & MINUS) && (int)ft_strlen(s) < p->a.width)
			s = ft_strjoinfree(" ", s, 0, 1);
		while (p->a.p & ZERO && (int)ft_strlen(s) < p->a.width)
			s = ft_strjoinfree("0", s, 0, 1);
	}
	else if (spec == 2)
	{
		if (s && p->a.precision != -1 && (int)ft_strlen(s) > p->a.precision)
			*(s + p->a.precision) = '\0';
		while (s && (p->a.p & MINUS) && (int)ft_strlen(s) < p->a.width)
			s = ft_strjoinfree(s, " ", 1, 0);
		while (s && !(p->a.p & MINUS) && (int)ft_strlen(s) < p->a.width)
			s = ft_strjoinfree(" ", s, 0, 1);
		if (!s)
			s = ft_strdup("(null)");
	}
	ft_putstr(s);
	spec = ft_strlen(s);
	free(s);
	return (spec);
}

int		speci_p(void *pointeur, t_printf *p)
{
	char	*cpy;
	char    *cpycpy;
	int		total;

	cpycpy = ft_ulltoa((unsigned long long)pointeur);
	cpy = ft_convert_base(cpycpy, "0123456789", "0123456789abcdef");
	free(cpycpy);
	while (p->a.precision != -1 && (int)ft_strlen(cpy) < p->a.precision)
		cpy = ft_strjoinfree("0", cpy, 0, 1);
	cpy = ft_strjoinfree("0x", cpy, 0, 1);
	while (p->a.p & MINUS && (int)ft_strlen(cpy) < p->a.width)
		cpy = ft_strjoinfree(cpy, " ", 1, 0);
	while (!(p->a.p & MINUS) && (int)ft_strlen(cpy) < p->a.width)
		cpy = ft_strjoinfree(" ", cpy, 0, 1);
	ft_putstr(cpy);
	total = ft_strlen(cpy);
	free(cpy);
	return (total);
}
