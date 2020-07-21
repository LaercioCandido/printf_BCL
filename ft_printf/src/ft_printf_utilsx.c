/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilsx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:16:11 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/21 16:45:19 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putflags(int condition, char c)
{
	int count;

	count = 0;
	while (condition--)
		count += ft_putchar(c);
	return (count);
}

int	ft_printf_utils_xa(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0 && flags->zero == 1)
		count += ft_putflags(flags->width - len, '0');
	else if (flags->minus == 0 && flags->zero == 0)
		count += ft_putflags(flags->width - len, ' ');
	count += ft_putstr(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - len, ' ');
	return (count);
}

int	ft_printf_utils_xb(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->point, ' ');
	count += ft_putflags(flags->point - len, '0');
	count += ft_putstr(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->point, ' ');
	return (count);
}

