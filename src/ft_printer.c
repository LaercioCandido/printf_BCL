/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int ft_printf_str(int n, int len, char c, char * num)
{
    int count;
    //mudar nome para xa?
    count = 0;
    while (n-- - len)
        count += ft_putchar(c);
    count += ft_putstr(num);
    return (count);
}


int ft_printf_xb(t_flags *flags, int len, char * num)
{
    int count;

    count = 0;
    if (flags->minus == 0 && flags->zero == 1)
        count += ft_printf_str(flags->width, len, '0', num);
    if (flags->minus == 0 && flags->zero == 0)
        count += ft_printf_str(flags->width, len, ' ', num);
    else
    {
        count += ft_putstr(num);
        while (flags->width-- - len)
            count += ft_putchar(' ');
    }
    return (count);
}

int ft_printf_xc(t_flags *flags, int len, char * num)
{
    int count;
    int point;

    count = 0;
    point = flags->point;
    if (flags->minus == 0)
        while (flags->width-- - point)
            count += ft_putchar(' ');

    while (flags->point-- - len)
        count += ft_putchar('0');
    count += ft_putstr(num);
    if (flags->minus == 1)
        while (flags->width-- - point)
            count += ft_putchar(' ');
    return (count);
}
