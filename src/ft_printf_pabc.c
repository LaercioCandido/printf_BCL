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
