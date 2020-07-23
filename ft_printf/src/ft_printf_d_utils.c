/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:52:50 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/23 18:06:09 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_utils_da(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (number < 0)
		{
			number = number * (-1);
			flags->point++;
			count += ft_putchar('-');
		}
	count += ft_putflags(flags->point - len, '0') + ft_putnbr(number);
	return (count);
}


int	ft_printf_utils_db(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (number < 0 && flags->point == -1)
	{
		number = number * (-1);
		flags->point++;
		if (flags->zero)
			count += ft_putchar('-') + ft_putflags(flags->width - len, '0');
		else
			count += ft_putflags(flags->width - len, ' ') + ft_putchar('-');
		count += ft_putnbr(number);
	}
	else if (number < 0)
	{
		while ((flags->point >= 0) && (flags->width-- - len))
			count += ft_putchar(' ');
		count += ft_putnbr(number);
	}
	else if (flags->zero && flags->point == -1)
		count += ft_putflags(flags->width - len, '0') + ft_putnbr(number);
	else
		count += ft_putflags(flags->width - len, ' ') + ft_putnbr(number);
	return (count);
}

int	ft_printf_utils_dc(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (number < 0)
		flags->point + 1;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->point, ' ');
	if (number < 0)
	{
		count += ft_putchar('-');
		number = number * (-1);
		len--;
	}
	count += ft_putflags(flags->point - len, '0') + ft_putnbr(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->point, ' ');
	return (count);
}

