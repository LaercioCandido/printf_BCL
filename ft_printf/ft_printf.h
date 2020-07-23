/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:16:36 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 19:37:35 by camilo           ###   ########.fr       */
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
void	checkflag(const char f, t_flags *flags);
int		readflag(t_flags *flags, const char *str);
int		ft_numlen(int num);
int 	ft_strlen(char *s);
char	*ft_itoa_base(unsigned long int n, char type);
int 	ft_printf_d(t_flags *flags, va_list args);
int		ft_printf_c(t_flags *flags, va_list args);
int		ft_printf_s(t_flags *flags, va_list args);
int		ft_printf_x(t_flags *flags, va_list args);
int		ft_printf_u(t_flags *flags, va_list args);
int		ft_printf_p(t_flags *flags, va_list args);
int		ft_printf_pct(t_flags *flags);
int		ft_printf(const char *str, ...);
int     ft_printf_sa(t_flags *flags, int len, char * str);
int     ft_printf_sb(t_flags *flags, int point, char * str);
int     ft_printf_sc(t_flags *flags, int len, int point, char * str);
void 	ft_printf_star(t_flags *flags, va_list args);
int		ft_isconversion(t_flags *flags, va_list args);
int		ft_printf_ua(t_flags *flags, int len, int number);
int		ft_printf_ub(t_flags *flags, int len, int number);
int		ft_printf_xa(t_flags *flags, int len, char *number);
int		ft_printf_xb(t_flags *flags, int len, char *number);
int    	ft_printf_pa(t_flags *flags);
int    	ft_printf_pb(t_flags *flags, int len, char *end_hex);
int    	ft_printf_pc(t_flags *flags, int len, char *end_hex);
int    	ft_printf_pd(t_flags *flags, int len, char *end_hex);
int 	ft_printf_dm(t_flags *flags);
int     ft_printf_da(int n, char c);



#endif
