/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:00:49 by bvidigal          #+#    #+#             */
/*   Updated: 2020/05/05 23:01:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFTPRINTF_H
# define __LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void    ft_putchar(char c);
void    ft_putnbr(int nb);
int	ft_isnum(char n);
int		ft_atoi(const char *str);
void	*ft_memset(void *dest, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int	ft_printf(const char *fmt, ...);
void	ft_puthex(unsigned long int nb);
size_t		ft_strlen(const char *s);

#endif
