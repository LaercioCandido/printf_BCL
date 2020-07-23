/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sabc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 22:49:43 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int     ft_printf_sa(t_flags *flags, int len, char * str)
{
    int count;

    count = 0;
    while ((flags->width-- - len) && !(flags->minus))
        count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
    while (*str)
        count += ft_putchar(*str++);
    while ((flags->width-- - len + 1) && flags->minus)
        count += ft_putchar(' ');
    return (count);
}

int     ft_printf_sb(t_flags *flags, int point, char * str)
{
    int count;

    count = 0;
    while ((flags->width-- - point) && !(flags->minus))
        count += ft_putchar(' ');
    while (flags->point-- && *str)
        count += ft_putchar(*str++);
    while ((flags->width-- - point + 1) && flags->minus)
        count += ft_putchar(' ');
    return (count);
}

int     ft_printf_sc(t_flags *flags, int len, int point, char * str)
{
    int count;

    count = 0;
    while ((flags->point-- > len) && flags->width-- > len)
        count += ft_putchar(' ');
    while (!len && flags->width-- > 0 && !flags->minus)
        count += ft_putchar(' ');
    while (point-- && *str)
        count += ft_putchar(*str++);
    while (flags->minus && flags->width-- && *str)
        count += ft_putchar(' ');
    return (count);
}
