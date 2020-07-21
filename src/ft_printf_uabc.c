/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uabc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_ua(t_flags *flags, int len, unsigned int number)
{
    int count;

    count = 0;
    if (flags->minus == 0)
    {
        while (flags->width-- - len)
                count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
        count += ft_putnbr_unsigned(number);
    }
    else
    {
        count += ft_putnbr_unsigned(number);
        while (flags->width-- - len)
            count += ft_putchar(' ');
    }
    return (count);
}


int ft_printf_ub(t_flags *flags, int len, unsigned int number)
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
    count += ft_putnbr_unsigned(number);
    if (flags->minus == 1)
        while (flags->width-- - point)
            count += ft_putchar(' ');
    return (count);
}
