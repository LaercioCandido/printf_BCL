/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:37:56 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/08 16:38:33 by rcamilo-         ###   ########.fr       */
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
	{
		count += ft_putchar(c);
		while (flags->width-- > 1)
			count += ft_putchar(' ');
	}
	else
	{
		while (flags->width-- > 1)
			count += ft_putchar(' ');
		count += ft_putchar(c);
	}
	return (count);
}
