/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:13:40 by ariperez          #+#    #+#             */
/*   Updated: 2019/07/19 12:56:06 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int     speci_c(char *cpy, t_printf *p)
{
	char    *s;
	int		spec;

	s = ft_strdup(cpy);
	while (p->a.p & MINUS && (int)ft_strlen(s) < p->a.width)
		s = ft_strjoinfree(s, " ", 1, 0);
	while (!(p->a.p & (MINUS | !ZERO)) && (int)ft_strlen(s) < p->a.width)
		s = ft_strjoinfree(" ", s, 0, 1);
	while (p->a.p & ZERO && (int)ft_strlen(s) < p->a.width)
		s = ft_strjoinfree("0", s, 0, 1);
	ft_putstr(s);
	spec = ft_strlen(s);
	free(s);
	return (spec);
}
