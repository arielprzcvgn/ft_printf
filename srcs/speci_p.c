/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speci_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:48 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/14 21:15:19 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		speci_p(void *pointeur, t_printf *p)
{
	char	*cpy;
	int		total;

	cpy = uitoa_printf((unsigned long long)pointeur, p, 16, "0123456789abcdef");
	if (pointeur == 0 && p->a.precision == 0)
		cpy = ft_strdup("");
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
