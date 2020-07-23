/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pabc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 19:30:35 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

include "../ft_printf.h"

int    ft_printf_pa(t_flags *flags)
{
    int    count;

    count = 0;
    while (flags->width-- - 2 > 0)
        count += ft_putchar(' ');
    count += ft_printf("0x");
    return (count);
}

int    ft_printf_pb(t_flags *flags, int len, char *end_hex)
{
    int    count;

    count = ft_printf("0x");
    while (flags->point-- - len)
        count += ft_putchar('0');
    count += ft_printf(end_hex);
    return (count);
}

int    ft_printf_pc(t_flags *flags, int len, char *end_hex)
{
    int    count;

    count = 0;
    len = len + 2;
    if (flags->minus == 0)
    {
        while (flags->width-- - len > 0)
            count += (flags->zero && flags->point == -1)
                ? ft_putchar('0') : ft_putchar(' ');
        count += ft_printf("0x%s", end_hex);
    }
    else
    {
        count += ft_printf("0x%s", end_hex);
        while (flags->width-- - len > 0)
            count += ft_putchar(' ');
    }
    return (count);
}

int    ft_printf_pd(t_flags *flags, int len, char *end_hex)
{
    int    count;
    int    point;

    count = 0;
    point = flags->point;
    if (flags->minus == 0)
        while (flags->width-- - point)
            count += ft_putchar(' ');
    count += ft_printf("0x");
    while (flags->point-- - len)
        count += ft_putchar('0');
    count += ft_printf(end_hex);
    if (flags->minus == 1)
        while (flags->width-- - point)
            count += ft_putchar(' ');
    return (count);
}
