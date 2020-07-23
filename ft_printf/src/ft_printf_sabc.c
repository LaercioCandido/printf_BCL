/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sabc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>


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
