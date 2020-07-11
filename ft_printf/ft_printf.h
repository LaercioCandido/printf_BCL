/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:16:36 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/11 15:38:32 by camilo           ###   ########.fr       */
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
int 	ft_printf_d(t_flags *flags, va_list args);
int		ft_printf_c(t_flags *flags, va_list args);
int		ft_printf_s(t_flags *flags, va_list args);
int		ft_printf_x(t_flags *flags, va_list args);
int		ft_printf_u(t_flags *flags, va_list args);
int		ft_printf(const char *str, ...);

#endif
