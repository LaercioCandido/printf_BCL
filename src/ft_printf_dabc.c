/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dabc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_dm(t_flags *flags)
{
    int count;

    count = 0;
    if(!(flags->point <= 0))
        flags->point++;
    if (flags->zero || flags->point > flags->width)
        count += ft_putchar('-');
    return (count);
}

int ft_printf_da(int n, int len, char c, int num)
{
    int count;

    count = 0;
    while (n-- - len)
        count += ft_putchar(c);
    if (num < 0)
        num = num * (-1);
    count += ft_putnbr(num);
    return (count);
}

int ft_printf_db(t_flags *flags, int len, int num)
{
    int count;

    count = 0;
    if (num < 0)
    {
        count += ft_printf_dm(flags);
        num = num * (-1);
    }
    while (flags->width-- - len)
            count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
    count += ft_putnbr(num);
    return (count);
}

int  ft_printf_dc(t_flags *flags, int len, int num)
{
    int count;

    count = 0;
    while (flags->width-- - len)
            count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
    count += ft_putnbr(num);
    return (count);
}

int  ft_printf_dd(t_flags *flags, int len, int num)
{
    int count;
    count = 0;
    if (flags->minus == 0)
    {
        if(flags->point == -1)
            count += ft_printf_db(flags, len, num);
        else if (flags->point >= 0)
            count += ft_printf_da(flags->width, len, ' ', num);
    }
    else
    {
        count += ft_putnbr(num);
        while (flags->width-- - len)
            count += ft_putchar(' ');
    }
    return (count);
}

int  ft_printf_de(t_flags *flags, int len, int num)
{
    int count;
    int point;

    count = 0;
    point = num < 0? flags->point + 1: flags->point;
    if (flags->minus == 0)
        while (flags->width-- - point)
            count += ft_putchar(' '); //removi tenario aqui
    if (num < 0)
    {
        count += ft_putchar('-');
        len--;
    }
    count += ft_printf_da(flags->point, len, '0', num);
    if (flags->minus == 1)
        while (flags->width-- - point)
            count += ft_putchar(' ');
    return (count);
}
