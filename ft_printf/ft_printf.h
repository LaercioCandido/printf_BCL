/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:45:50 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/10 23:45:50 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_flags{
	int		minus;
	int		zero;
	int		star;
	int		point;
	int		width;
	int		len;
	char	type;
} 		t_flags;

void	init(t_flags *flags);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_numlen_unsigned(unsigned int num);
char	*ft_strjoin(char const *s1, char const *s2);
static size_t	nbstrlen(const char *str);
int		ft_putstr(char *s);
void	checkflag(const char f, t_flags *flags);
int		readflag(t_flags *flags, const char *str);
int		ft_numlen(int num);
int 	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		digitcounter(unsigned long int n);
char	*ft_itoa_base(unsigned long int n, char type);
int 	ft_printf_d(t_flags *flags, va_list args);
int		ft_printf_c(t_flags *flags, va_list args);
int		ft_printf_s(t_flags *flags, va_list args);
int		ft_printf_x(t_flags *flags, va_list args);
int		ft_printf_u(t_flags *flags, va_list args);
int		ft_printf_pct(t_flags *flags);
int		ft_printf(const char *str, ...);
int		ft_printf_p(t_flags *flags, va_list args);
char	*ft_strdup(const char *s1);
int		ft_putflags(int condition, char c);
int		ft_printf_utils_xa(t_flags *flags, int len, char *number);
int		ft_printf_utils_xb(t_flags *flags, int len, char *number);
int		ft_printf_utils_ua(t_flags *flags, int len, int number);
int		ft_printf_utils_ub(t_flags *flags, int len, int number);
void	ft_printf_star(t_flags *flags, va_list args);
int 	ft_isconversion(t_flags *flags, va_list args);
int		ft_isnum(int c);
void 	ft_printf_star2(t_flags *flags, va_list args);











#endif
