/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:02:10 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/21 23:15:40 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_utils_ua(t_flags *flags, int len, int number)
{
	int count;
	count = 0;
	if (flags->minus == 0)
	{
		if (flags->zero && flags->point == -1)
			count += ft_putflags(flags->width - len, '0');
		else
			count += ft_putflags(flags->width - len, ' ');
		count += ft_putnbr_unsigned(number);
	}
	else
		count += ft_putnbr_unsigned(number) + ft_putflags(flags->width - len, ' ');
	return (count);
}

int	ft_printf_utils_ub(t_flags *flags, int len, int number)
{
	int count;

	count = 0;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->point, ' ');
	count += ft_putflags(flags->point - len, '0');
	count += ft_putnbr_unsigned(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->point, ' ');
	return (count);
}
