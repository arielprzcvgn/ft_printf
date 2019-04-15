/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:30:37 by ariperez          #+#    #+#             */
/*   Updated: 2019/03/26 16:07:32 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_param	initialize(t_param par)
{
	par.flags.minus = 0;
	par.flags.plus = 0;
	par.flags.space = 0;
	par.flags.zero = 0;
	par.flags.hash = 0;
	par.width = 0;
	par.precision = -1;
	par.length = 0;
	par.ret = 0;
	return (par);
}

char	*base(char *nbr)
{
	if (nbr[0] == '0')
	{
		if (nbr[1] == 'b')
			return ("01");
		else if (nbr[1] == 'x')
			return ("0123456789abcdef");
		else
			return ("01234567");
	}
	return ("0123456789");
}

char	*chartostring(char c)
{
	char	*string;

	string = malloc(2);
	*string = c;
	*(string + 1) = '\0';
	return (string);
}
