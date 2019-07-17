/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:57:56 by ariperez          #+#    #+#             */
/*   Updated: 2019/05/29 16:22:22 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned long	to_base_ten(char *nbr, char *base_from)
{
	int				i;
	unsigned long	base;
	unsigned long	base_ten;
	unsigned long	number;

	base = ft_strlen(base_from);
	i = 0;
	base_ten = 0;
	while (nbr[i] != '\0')
	{
		number = 0;
		while (base_from[number] != nbr[i])
			number++;
		base_ten = base_ten * base + number;
		i++;
	}
	return (base_ten);
}

char			*from_base_ten(unsigned long nbr, char *base_to)
{
	int				i;
	unsigned long	base;
	char			*final_base;
	unsigned long	cmpt;
	int				j;

	base = ft_strlen(base_to);
	cmpt = nbr;
	j = 0;
	while ((cmpt /= base) != 0)
		j++;
	final_base = (char*)malloc(sizeof(*final_base) * (j + 2));
	final_base[j - 1] = '\0';
	while (j != -1)
	{
		i = 0;
		while ((unsigned long)i != nbr % base)
			i++;
		final_base[j] = base_to[i];
		nbr /= base;
		j--;
	}
	return (final_base);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return (from_base_ten(to_base_ten(nbr, base_from), base_to));
}
