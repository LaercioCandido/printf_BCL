/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:11:38 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 19:28:51 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_d(t_flags *flags, va_list args)
{
	int len;
	int point;
	int	number;
	int count;

	ft_printf_star(flags, args);
	number = va_arg(args, int);
	len = ft_numlen(number);
	count = 0;
	if (flags->point == 0 && number == 0)
	{
		// while (flags->width--)
		// 	count += ft_putchar(' ');
		// return (count);
		count += ft_printf_da(flags->width, ' ');
	}
	else if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_putnbr(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		if (number < 0)
		{
			// number = number * (-1);
			// flags->point++;
			// count += ft_putchar('-');
			count += ft_printf_dm(flags);
		}
		// while (flags->point-- - len)
		// 	count += ft_putchar('0');
		// count += ft_putnbr(number);
		count += ft_printf_da(flags->point - len, '0') + ft_putnbr(number);
	}
	else if (flags->width >= len && len > flags->point)
	{
		if (flags->minus == 0)
		{
			if (number < 0 && flags->point == -1)
			{
				number = number * (-1);
				flags->point++;
				if (flags->zero)
				{
					count += ft_putchar('-') + ft_printf_da(flags->width - len,  '0');
					// while (flags->width-- - len)
					// 	count += ft_putchar('0');
				}
				else
				{
					// while (flags->width-- - len)
					// 	count += ft_putchar(' ');
					count += ft_printf_da(flags->width - len,  ' ') + ft_putchar('-');
					// count += ft_putchar('-');
				}
				count += ft_putnbr(number);
			}
			else if (number < 0)
			{
				while ((flags->point >= 0) && (flags->width-- - len))
					count += ft_putchar(' ');
				count += ft_putnbr(number);
			}
			else
			{
				while (flags->width-- - len)
					count += (flags->zero && flags->point == -1)
						? ft_putchar('0') : ft_putchar(' ');
				count += ft_putnbr(number);
			}
		}
		else
		{
			count += ft_putnbr(number);
			while (flags->width-- - len)
				count += ft_putchar(' ');
		}
	}
	else if (flags->width > flags->point && flags->point >= len)
	{
		point = number < 0 ? flags->point + 1 : flags->point;
		if (flags->minus == 0)
			while (flags->width-- - point)
				count += ft_putchar(' ');
		if (number < 0)
		{
			count += ft_putchar('-');
			number = number * (-1);
			len--;
		}
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_putnbr(number);
		if (flags->minus == 1)
			while (flags->width-- - point)
				count += ft_putchar(' ');
	}
	return (count);
}
