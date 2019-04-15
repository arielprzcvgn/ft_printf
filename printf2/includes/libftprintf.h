/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:32:50 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/08 18:53:39 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define MAX(a, b)		(a < b) ? b : a

typedef struct		s_ret
{
	int				sign;
	int				zeros;
	int				str;
	int				space;
}					t_ret;

typedef struct		s_param
{
	int				minus;
	int				sign;
	int				hash;
	int				width;
	int				precision;
	int				length;
	t_ret			arg;
	int				ret;
}					t_param;

int					ft_printf(char *str, ...);

char				*specifier(char *str, va_list ap, t_param *par);
char				*length(char *str, va_list ap, t_param *par);
char				*precision(char *str, va_list ap, t_param *par);
char				*width(char *str, va_list ap, t_param *par);
char				*flags(char *str, va_list ap, t_param *par);

t_param				initialize(t_param par);
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
