/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:39:21 by ariperez          #+#    #+#             */
/*   Updated: 2019/08/14 20:53:25 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <limits.h>
#include <stdio.h>

int		main(void)
{
	ft_printf("\n%i     Ft_printf\n", ft_printf("%x", 0x21));
	printf("\n%i        Original\n", printf("%lx, %lx", 0ul, ULONG_MAX));
	return (0);
}
