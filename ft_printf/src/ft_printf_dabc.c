/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dabc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 19:30:35 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int ft_printf_dm(t_flags *flags)
{
    int count;

    count = 0;
    if(!(flags->point <= 0))
        flags->point++;
    if (flags->zero || (flags->point > flags->width))
        count += ft_putchar('-');
    return (count);
}

int     ft_printf_da(int n, char c)
{
    int count;

    count = 0;
    while (n--)
        count += ft_putchar(c);
    return (count);
}
