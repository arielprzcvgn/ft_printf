/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:13:40 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/18 20:50:46 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		put_c(t_printf *p, char *s)
{
	int		total;

	p->a.zeros = (p->a.p & ZERO && !(p->a.p & MINUS)) ? p->a.width - 1 : 0;
	p->a.str = 1;
	p->a.space = (!(p->a.p & ZERO) || p->a.p & MINUS) ? p->a.width - 1 : 0;
	total = MAX(p->a.zeros + p->a.str + p->a.space, p->a.str);
	while (!(p->a.p & (MINUS | ZERO)) && 0 < p->a.space--)
		write(1, " ", 1);
	while (p->a.p & (!MINUS | ZERO) && 0 < p->a.zeros--)
		write(1, "0", 1);
	write(1, s, 1);
	while (p->a.p & MINUS && 0 < p->a.space--)
		write(1, " ", 1);
	free(s);
	return (total);
}

int		speci_c(t_printf *p, int pc)
{
	char	*s;
	char	str[2];

	if (pc)
		s = ft_strdup("%");
	else
	{
		str[0] = va_arg(p->ap, int);
		str[1] = '\0';
		s = ft_strdup(str);
	}
	return (put_c(p, s));
}
