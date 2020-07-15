/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:46:45 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/10 23:46:45 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_d(t_flags *flags, va_list args)
{
	int len;
	int point;
	int	number;
	int count;

	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->minus = 1;
	}
	if (flags->point < 0)
		flags->point = -1;
	number = va_arg(args, int);
	len = ft_numlen(number);
	count = 0;
	if(flags->point == 0 && number == 0) // qq isso aqui faz mesmo?
	{
		//ft_putchar('H');
		return (count);
	}
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
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_putnbr(number);
	}
	else if (flags->width >= len && len > flags->point)
	{

		if (flags->minus == 0)
		{
			if (number < 0 && flags->point == -1)
			{
				number = number * (-1);
				flags->point++;
				count += ft_putchar('-');
				while (flags->width-- - len)
					count += flags->zero ? ft_putchar('0') : ft_putchar('H'); //esse tenario nao roda else
				count += ft_putnbr(number);
			}
			else if (number < 0)
			{
				while ((flags->point >= 0) && (flags->width-- - len))
					count += flags->zero ? ft_putchar('0') : ft_putchar(' '); //removi tenario
				count += ft_putnbr(number);
			}
			else
			{
				while (flags->width-- - len)
						count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
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

		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_putnbr(number);
		if (flags->minus == 1)
			while (flags->width-- - point)
				count += ft_putchar(' ');
	}
	return (count);
}
