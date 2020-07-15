/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 19:30:35 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_printf_p(t_flags *flags, va_list args)
{
	int		count;
	unsigned long int		end_dec;
	int		len;
	char	*end_hex;
	int		point;

	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	end_dec = va_arg(args, unsigned long int);
	end_hex = ft_itoa_base(end_dec, 'x');
	count = 0;
	len = ft_strlen(end_hex);
	if (flags->point == 0 && end_dec == 0)
	{
		while (flags->width-- - 2 > 0)
			count +=  ft_putchar(' ');
		count += ft_printf("0x");
		return (count);
	}
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_printf("0x%s", end_hex);
	else if (flags->point > len && flags->point >= flags->width)
	{
		count = ft_printf("0x");
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_printf(end_hex);
	}
	else if (flags->width >= len && len > flags->point)
	{
		len = len + 2;
		if (flags->minus == 0)
		{
			while (flags->width-- - len > 0)
				count += (flags->zero && flags->point == -1)
					? ft_putchar('0') : ft_putchar(' ');
			count += ft_printf("0x%s", end_hex);
		}
		else
		{
			count += ft_printf("0x%s", end_hex);
			while (flags->width-- - len > 0)
				count += ft_putchar(' ');
		}
	}
	else if (flags->width > flags->point && flags->point >= len)
	{
		point = flags->point;
		if (flags->minus == 0)
			while (flags->width-- - point)
				count += ft_putchar(' ');
		count += ft_printf("0x");
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_printf(end_hex);
		if (flags->minus == 1)
			while (flags->width-- - point)
				count += ft_putchar(' ');
	}
	free(end_hex);
	return (count);
}
