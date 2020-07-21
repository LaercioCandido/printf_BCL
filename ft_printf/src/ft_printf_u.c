/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 01:41:32 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/21 18:32:43 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_numlen_unsigned(unsigned int num)
{

	int i;

	i = 1;
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int		ft_putnbr_unsigned(unsigned int n)
{
	int			count;

	count = 1;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + 48);
	return (count);
}

int ft_printf_u(t_flags *flags, va_list args)
{
	int     count;
	int		len;
	unsigned int 	number;
	//int 	point;

	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	number = va_arg(args, unsigned int);
	count = 0;
	len = ft_numlen_unsigned(number);
	if(flags->point == 0 && number == 0)
		return (count);
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_putnbr_unsigned(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		ft_putflags(flags->point - len, '0');
		count += ft_putnbr_unsigned(number);
	}
	else if (flags->width >= len && len > flags->point)
		ft_printf_utils_ua(flags, len, number);
	else if (flags->width > flags->point && flags->point >= len)
		ft_printf_utils_ub(flags, len, number);
	return (count);
}
