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
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_putnbr(number);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_printf_utils_da(flags, len, number);
	else if (flags->width >= len && len > flags->point)
	{
		if (flags->minus == 0)
			ft_printf_utils_db(flags, len, number);
		else
			count += ft_putnbr(number) + ft_putflags(flags->width - len, ' ');
	}
	else if (flags->width > flags->point && flags->point >= len)
		ft_printf_utils_dc(flags, len, number);
	return (count);
}
