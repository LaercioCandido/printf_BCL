/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:46:21 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/10 23:46:21 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		digitcounter(unsigned long int n)
{
	if (!(n / 16))
		return (1);
	else
		return (digitcounter(n / 16) + 1);
}

char	*ft_itoa_base(unsigned long int n, char type)
{
	char	*hexnumber;
	int		len;
	char	*base;

	base = type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	len = digitcounter(n);
	if (!(hexnumber = malloc((len + 1) * sizeof(*hexnumber))))
		return (NULL);
	hexnumber[len] = '\0';
	while (len--)
	{
		hexnumber[len] = base[n % 16];
		n /= 16;
	}
	return (hexnumber);
}

int		ft_printf_x(t_flags *flags, va_list args)
{
	int		count;
	int		dec;
	int		len;
	char	*number;
	int		point;

	ft_printf_star(flags, args);
	dec = va_arg(args, int);
	number = ft_itoa_base((unsigned int)dec, flags->type);
	count = 0;
	len = ft_strlen(number);
	if (flags->point == 0 && dec == 0)
	{
		while (flags->width--)
			count += ft_putchar(' ');
		return (count);
	}
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_printf(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_printf(number);
	}
	else if (flags->width >= len && len > flags->point)
	{
		if (flags->minus == 0)
		{
			while (flags->width-- - len)
				count += (flags->zero && flags->point == -1)
					? ft_putchar('0') : ft_putchar(' ');
			count += ft_printf(number);
		}
		else
		{
			count += ft_printf(number);
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
		count += ft_printf(number);
		if (flags->minus == 1)
			while (flags->width-- - point)
				count += ft_putchar(' ');
	}
	free(number);
	return (count);
}
