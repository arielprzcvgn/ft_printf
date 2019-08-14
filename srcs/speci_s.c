/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:15 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/08 14:29:25 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		speci_s(char *cpy, t_printf *p)
{
	char	*s;
	int		spec;

	s = ft_strdup(cpy);
	if (!s)
		s = ft_strdup("(null)");
	if (s && p->a.precision != -1 && (int)ft_strlen(s) > p->a.precision)
		*(s + p->a.precision) = '\0';
	while (s && (p->a.p & MINUS) && (int)ft_strlen(s) < p->a.width)
		s = ft_strjoinfree(s, " ", 1, 0);
	while (s && !(p->a.p & MINUS) && (int)ft_strlen(s) < p->a.width)
		s = ft_strjoinfree(" ", s, 0, 1);
	ft_putstr(s);
	spec = ft_strlen(s);
	free(s);
	return (spec);
}
