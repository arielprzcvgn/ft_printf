/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:32:50 by ariperez          #+#    #+#             */
/*   Updated: 2019/07/17 20:47:36 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define MAX(a, b)		(a < b) ? b : a
# define ABS(a)			(a < 0) ? -a : a
# define BOOL(a)		(a > 0) ? 1 : 0

# define MINUS			(1 << 0)
# define ZERO			(1 << 1)
# define PLUS			(1 << 2)
# define SPACE			(1 << 3)
# define HASH			(1 << 4)
# define HASH0			(1 << 5)
# define HASH1			(1 << 6)
# define WIDTH			(1 << 7)
# define PRECI			(1 << 8)
# define HH				(1 << 9)
# define H				(1 << 10)
# define L				(1 << 11)
# define LL				(1 << 12)
# define J				(1 << 13)
# define Z				(1 << 14)
# define LLL			(1 << 15)


typedef struct		s_argument
{
	short           p;
	int             width;
	int             precision;
	char            *arg;
	int             sign;
	int             zeros;
	int             str;
	int             space;
}					t_argument;

typedef struct		s_printf
{
	char			*format;
	int				printed;
	va_list			ap;
	t_argument		a;
}					t_printf;

int					ft_printf(const char *format, ...);

char				*specifier(t_printf *p);
char				*length(t_printf *p);
char				*precision(t_printf *p);
char				*width(t_printf *p);
char				*flags(t_printf *p);

char				*base(char *nbr);
char				*chartostring(char c);
char				*itoa_printf(intmax_t n, t_printf *p);
char				*uitoa_printf(uintmax_t n, t_printf *p);
char				*ft_ulltoa(unsigned long long n);

int					speci_c_s(int spec, char *cpy, t_printf *p);
int					speci_p(void *pointeur, t_printf *p);

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
void				*ft_bzero(void *b, size_t len);

#endif
