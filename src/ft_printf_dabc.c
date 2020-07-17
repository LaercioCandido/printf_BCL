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
    flags->point++;
    if (flags->zero)
        count += ft_putchar('-');
    return (count);
}

int ft_printf_da(int n, int len, char c, int num)
{
    int count;

    count = 0;
    while (n-- - len)
        count += ft_putchar(c);
    count += ft_putnbr(num);
    return (count);
}

int ft_printf_db(t_flags *flags, int len, int num)
{
    int count;

    count = 0;
    while (flags->width-- - len)
            count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
    count += ft_putnbr(num);
    return (count);
}
