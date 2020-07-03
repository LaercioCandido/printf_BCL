/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:11:38 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/02 21:33:22 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_d(t_flags *flags, int number)
{
	int len;
	int point;

	len = ft_numlen(number);

	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		ft_putnbr(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		if (number < 0)
		{
			number = number * (-1);
			flags->point++;
			ft_putchar('-');
		}
		while (flags->point-- - len)
			ft_putchar('0');
		ft_putnbr(number);
	}
	else if (flags->width >= len && len > flags->point)
	{
		if (flags->minus == 0)
		{
			while (flags->width-- - len)
				ft_putchar(' ');
			ft_putnbr(number);
		}
		else
		{
			ft_putnbr(number);
			while (flags->width-- - len)
				ft_putchar(' ');
		}

	}
	else if (flags->width > flags->point && flags->point >= len)
	{
		point = number < 0? flags->point + 1: flags->point;
		if (flags->minus == 0)
			while (flags->width-- - point)
				ft_putchar(' ');
		if (number < 0)
		{
			ft_putchar('-');
			number = number * (-1);
			len--;
		}

		while (flags->point-- - len)
			ft_putchar('0');
		ft_putnbr(number);
		if (flags->minus == 1)
			while (flags->width-- - point)
				ft_putchar(' ');
	}
	return (0);
}
