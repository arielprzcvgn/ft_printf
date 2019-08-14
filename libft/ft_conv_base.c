/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:57:56 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/14 21:01:26 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

unsigned long	to_base_ten(char *base_from, char *nbr)
{
	int				i;
	unsigned long	j;
	unsigned long	base;
	unsigned long	base_ten;

	base = ft_strlen(base_from);
	i = -1;
	base_ten = 0;
	while (nbr[++i])
	{
		j = 0;
		while (base_from[j] != nbr[i])
			j++;
		base_ten = base_ten * base + j;
	}
	return (base_ten);
}

char			*ft_conv_base(char *nbr, char *base_from, char *base_to)
{
	int				i;
	unsigned long	base;
	unsigned long	base_ten;
	unsigned long	number;
	char			*final_base;

	base_ten = to_base_ten(base_from, nbr);
	base = ft_strlen(base_to);
	number = base_ten;
	i = 0;
	while ((number /= base) != 0)
		i++;
	if ((final_base = malloc(i + 1)) == NULL)
		return (NULL);
	final_base[i + 1] = '\0';
	while (i >= 0)
	{
		final_base[i] = base_to[base_ten % base];
		base_ten /= base;
		i--;
	}
	return (final_base);
}
