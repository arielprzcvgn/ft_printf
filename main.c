/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:39:21 by ariperez          #+#    #+#             */
/*   Updated: 2019/09/03 23:32:07 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <limits.h>
#include <stdio.h>

int		main(void)
{
	ft_printf("\n%i		Ft_printf\n", ft_printf("%'d", 542513884));
	printf("\n%i			Original\n", printf("%'d", 542035103));
}
