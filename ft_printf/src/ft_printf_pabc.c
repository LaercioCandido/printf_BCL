/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pabc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int  ft_printf_pa(t_flags *flags, int len, char * number, void * dec)
{
    int count;

    count = 0;
    count += dec == 0 ? ft_putstr(number) : ft_printf("0x");
    while (flags->point-- - len)
        count += ft_putchar('0');
    count += ft_putstr(number);
    return (count);
}

int  ft_printf_pb(t_flags *flags, int len, char * number, void * dec)
{
    int count;

    count = 0;
    len = len + 2;
    if (flags->minus == 0)
    {
        while (flags->width-- - len)
                count += ft_putchar(' ');
        count += dec == 0 ? ft_putstr(number) : ft_printf("0x") + ft_putstr(number);
    }
    else
    {
        count += dec == 0 ? ft_putstr(number) :  ft_printf("0x") + ft_putstr(number);
        while (flags->width-- - len)
            count += ft_putchar(' ');
    }
    return (count);
}

int  ft_printf_pc(t_flags *flags, int len, char * number, void * dec)
{
    int count;
    int point;

    count = 0;
    point = dec == 0 ? flags->point : flags->point + 2;
    if (flags->minus == 0)
        while (flags->width-- - point)
            count += ft_putchar(' ');
    if (dec != 0)
        count += ft_printf("0x");
    while (flags->point-- - len  && flags->minus == 0)
        count += dec == 0? ft_putchar(' ') : ft_putchar('0');
    count += ft_putstr(number);
    if (flags->minus == 1)
        while (flags->width-- - point + len + 5)
            count += ft_putchar(' ');
    return (count);
}
