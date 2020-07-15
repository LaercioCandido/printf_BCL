/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
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
	/*
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
	*/
	return (count);
}
