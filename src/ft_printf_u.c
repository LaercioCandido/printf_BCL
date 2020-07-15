/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_numlen_unsigned(unsigned int num)
{

	int i;

	i = 1;
	/*
	if (num < 0)
		i++; */
	while (num >= 10)// || num <= -10)
	{
		num /= 10;
		i++;
		//printf("num%d: %d\n", i, num);
	}
	return (i);
}

int		ft_putnbr_unsigned(unsigned int n)
{
	//unsigned	i;
	int			count;

	count = 1;
	/*if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
		count++;
	}
	else
		i = n;
		*/
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + 48);
	return (count);
}

int ft_printf_u(t_flags *flags, va_list args)
{
	int     count;
	//int		dec;
	int		len;
	unsigned int 	number;
	int 	point;

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
	//printf("len: %d", len);
	if(flags->point == 0 && number == 0)
		return (count);
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_putnbr_unsigned(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_putnbr_unsigned(number);
	}
	else if (flags->width >= len && len > flags->point)
	{

			if (flags->minus == 0)
			{
				while (flags->width-- - len)
						count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
				count += ft_putnbr_unsigned(number);
			}
			else
			{
				count += ft_putnbr_unsigned(number);
				while (flags->width-- - len)
					count += ft_putchar(' ');
			}

		}
		else if (flags->width > flags->point && flags->point >= len)
		{
			point = flags->point;
			if (flags->minus == 0)
				while (flags->width-- - point)
					count += ft_putchar(' ');

			while (flags->point-- - len)
				count += ft_putchar('0');
			count += ft_putnbr_unsigned(number);
			if (flags->minus == 1)
				while (flags->width-- - point)
					count += ft_putchar(' ');
		}
	//free(number);
	return (count);
}
