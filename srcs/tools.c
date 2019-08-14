/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:30:37 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/14 21:20:37 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*itoa_printf(intmax_t n, t_printf *p)
{
	char		*number;
	intmax_t	tmp;
	int			i;

	i = 0;
	tmp = 1;
	p->a.neg = n < 0 ? 1 : 0;
	if (n == 0 && p->a.precision == 0)
		return (ft_strdup(""));
	n = ABS(n);
	while (tmp <= n / 10 && ++i)
		tmp *= 10;
	if ((number = malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (tmp > 0)
	{
		*(number + i) = (n / tmp) + 48;
		n = n % tmp;
		tmp /= 10;
		i++;
	}
	number[i] = '\0';
	return (number);
}

char	*uitoa_printf(uintmax_t n, t_printf *p, int b, char *base)
{
	char		*number;
	uintmax_t	tmp;
	int			i;

	i = 0;
	tmp = 1;
	number = NULL;
	if (n == 0 && p->a.precision == 0)
		return (ft_strdup(""));
	while (tmp <= n / b && ++i)
		tmp *= b;
	if ((number = malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (tmp > 0)
	{
		number[i++] = base[n / tmp];
		n = n % tmp;
		tmp /= b;
	}
	number[i] = '\0';
	return (number);
}
