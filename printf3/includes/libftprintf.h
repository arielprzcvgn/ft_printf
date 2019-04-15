/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:32:50 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/15 21:05:30 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define MAX(a, b)		(a < b) ? b : a
# define ABS(a)			(a < 0) ? -a : a;

# define MINUS			(1 << 0)
# define ZERO			(1 << 1)
# define PLUS			(1 << 2)
# define SPACE			(1 << 3)
# define HASH0			(1 << 4)
# define HASH1			(1 << 5)
# define WIDTH			(1 << 6)
# define PRECI			(1 << 7)
# define HH				(1 << 8)
# define H				(1 << 9)
# define L				(1 << 10)
# define LL				(1 << 11)
# define J				(1 << 12)
# define Z				(1 << 13)
# define LLL			(1 << 14)


typedef struct		s_printf
{
	char			*format;
	int				printed;
	va_list			ap;
	short			p;
	int				width;
	int				precision;
	int             sign;
	int             zeros;
	int             str;
	int             space;
}					t_printf;

int					ft_printf(char *str, ...);

char				*specifier(char *str, va_list ap, t_param *par);
char				*length(char *str, va_list ap, t_param *par);
char				*precision(char *str, va_list ap, t_param *par);
char				*width(char *str, va_list ap, t_param *par);
char				*flags(char *str, va_list ap, t_param *par);

char				*base(char *nbr);
char				*chartostring(char c);
char				*ft_lltoa(long long n);
char				*ft_ulltoa(unsigned long long n);

int					speci_c_s(int spec, char *s, t_param *par);
int					speci_p(void *p, t_param *par);

size_t				ft_strlen(const char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2);
char				*ft_strdup(char *s1);

#endif
