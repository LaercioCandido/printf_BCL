/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:46:53 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/10 23:46:53 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_c(t_flags *flags, va_list args)
{
	int count;
	char c;
	c = va_arg(args, int);
	count = 0;
	if (flags->minus == 1)
		count += ft_putchar(c);
	while (flags->width-- > 1)
		count += ft_putchar(' ');
	if (flags->minus == 0)
		count += ft_putchar(c);
	return (count);
}
