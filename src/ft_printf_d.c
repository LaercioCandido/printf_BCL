/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_d(t_flags *flags, va_list args)
{
	int len;
	int point;
	int	number;
	int count;

	ft_printf_star(flags, args);
	number = va_arg(args, int);
	len = ft_numlen(number);
	count = 0;
	if(flags->point == 0 && number == 0)
		return (count);
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_putnbr(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		if (number < 0)
		{
			number = number * (-1);
			flags->point++;
			count += ft_putchar('-');

		}
		count += ft_printf_da(flags->point, len, '0', number);
	}
	else if (flags->width >= len && len > flags->point)
	{

		if (flags->minus == 0)
		{
			if (number < 0 && flags->point == -1)
			{
				if (flags->zero)
					number = number * (-1);
				count += ft_printf_dm(flags);
				count += ft_printf_db(flags, len, number);
			}
			else if (number < 0)
				count += ft_printf_db(flags, len, number);
			else
				count += ft_printf_db(flags, len, number);
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
		point = number < 0? flags->point + 1: flags->point;
		if (flags->minus == 0)
			while (flags->width-- - point)
				count += ft_putchar(' '); //removi tenario aqui
		if (number < 0)
		{
			count += ft_putchar('-');
			number = number * (-1);
			len--;
		}
		count += ft_printf_da(flags->point, len, '0', number);
		if (flags->minus == 1)
			while (flags->width-- - point)
				count += ft_putchar(' ');
	}
	return (count);
}
