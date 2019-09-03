/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:30:37 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 23:33:23 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		itoa_printf(intmax_t n, t_printf *p)
{
	int			i;
	intmax_t	tmp;

	if (n == 0 && p->a.precision == 0)
		return (0);
	p->a.sign = (p->a.p & PLUS || p->a.p & SPACE || n < 0) ? 1 : 0;
	i = (p->a.p & PLUS) ? '+' : ' ';
	ft_memset(p->buffer + p->c, (n < 0) ? '-' : i, p->a.sign);
	if (n == -9223372036854775807 - 1 && (i = 20))
		ft_memcpy(p->buffer + p->a.sign, "9223372036854775808", i - 1);
	else
	{
		n = ABS(n);
		tmp = 1;
		i = p->a.sign;
		while (tmp <= n / 10)
			tmp *= 10;
		while (tmp > 0 && ++i)
		{
			p->buffer[i - 1] = (n / tmp) + 48;
			n = n % tmp;
			tmp = tmp / 10;
		}
	}
	return (i);
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

char	*ft_ulltoa(unsigned long long n)
{
	char				*number;
	unsigned long long	pow;
	int					i;

	pow = 1;
	i = 0;
	while (pow <= (n / 10) && (i += 1))
		pow *= 10;
	if ((number = (char *)malloc(i + 2)) == NULL)
		return (NULL);
	i = 0;
	while (pow > 0)
	{
		number[i++] = (n / pow) + 48;
		n = n % pow;
		pow /= 10;
	}
	number[i] = '\0';
	return (number);
}

void	apostrophe(t_printf *p)
{
	int		i;
	int		j;

	i = 0;
	while (p->buffer[i] != '\0' && p->buffer[i] != '.')
		i++;
	j = i;
	i++;
	while (--i)
	{
		if ((j - i + 1) % 4 == 0 && '0' <= p->buffer[i - 1] &&
				p->buffer[i - 1] <= '9')
		{
			ft_memmove(p->buffer + i + 1, p->buffer + i, p->a.str - i);
			ft_memset(p->buffer + i, TROPHY, 1);
			p->a.str++;
			j++;
		}
	}
}
