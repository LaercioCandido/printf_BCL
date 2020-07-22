/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:46:32 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/10 23:46:32 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;
	int		len;
	int		point;

	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	count = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	point = flags->point > len ? len : flags->point;
	if (flags->len == 0 || (flags->point == -1 && len >= flags->width))
		while (*str)
			count += ft_putchar(*str++);
	else if (flags->point == -1 && flags->width > len)
	{
		while ((flags->width-- - len) && !(flags->minus))
			count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
		while (*str)
			count += ft_putchar(*str++);
		while ((flags->width-- - len + 1) && flags->minus)
			count += ft_putchar(' ');
	}
	else if (flags->width > flags->point)
	{
		while ((flags->width-- - point) && !(flags->minus))
			count += ft_putchar(' ');
		while (flags->point-- && *str)
			count += ft_putchar(*str++);
		while ((flags->width-- - point + 1) && flags->minus)
			count += ft_putchar(' ');
	}
	else if (flags->width <= flags->point)
	{


		//while (flags->width-- > len && len)

		while ((flags->point-- > len) && flags->width-- > len)
			count += ft_putchar(' ');
		while (!len && flags->width-- > 0 && !flags->minus)
			count += ft_putchar(' ');
		while (point-- && *str)
			count += ft_putchar(*str++);
		while (flags->minus && flags->width-- && *str)
			count += ft_putchar(' ');
	}
	return (count);
}
