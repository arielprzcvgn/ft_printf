/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:28:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/07/12 12:24:16 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
	printf("\n%i\n", ft_printf(argv[1], ft_atoi(argv[2])));
	printf("\n%i\n", printf(argv[1], ft_atoi(argv[2])));
	return (0);
}
