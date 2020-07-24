/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:11:38 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/23 23:12:02 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printf_da(t_flags *flags, int len, int number)
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

static int	ft_printf_db(t_flags *flags, int len, int number)
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

static int	ft_printf_dc(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (number < 0)
		flags->point++;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->point, ' ');
	if (number < 0)
	{
		count += ft_putchar('-');
		number = number * (-1);
	}
	count += ft_putflags(flags->point - len, '0') + ft_putnbr(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->point, ' ');
	return (count);
}

int			ft_printf_d(t_flags *flags, va_list args)
{
	int len;
	int	number;
	int count;

	ft_printf_star(flags, args);
	number = va_arg(args, int);
	len = ft_numlen(number);
	count = 0;
	if (flags->point == 0 && number == 0)
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len > flags->point))
		count += ft_putnbr(number);
	else if (flags->point >= len && flags->point >= flags->width)
		count += ft_printf_da(flags, len, number);
	else if (flags->width >= len && len > flags->point)
	{
		if (flags->minus == 0)
			count += ft_printf_db(flags, len, number);
		else
			count += ft_putnbr(number) + ft_putflags(flags->width - len, ' ');
	}
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_dc(flags, len, number);
	return (count);
}
