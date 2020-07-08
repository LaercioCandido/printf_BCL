/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/08 16:39:06 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_s(t_flags *flags, va_list args)
{
	int count;
	char *str;
	int len;
	int point;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	count = 0;
	point = flags->point > len ? len : flags->point;
	if (flags->len == 0 || (flags->point == -1 && len >= flags->width) )
		while(*str)
			count += ft_putchar(*str++);
	else if (flags->point == -1 && flags->width > len)
	{
		while(flags->width-- - len)
			count += ft_putchar(' ');
		while(*str)
			count += ft_putchar(*str++);
	}
	else if (flags->width > flags->point)
	{
		while((flags->width-- - point) && !(flags->minus))
		 	count += ft_putchar(' ');
		while(flags->point-- && *str)
			count += ft_putchar(*str++);
		while((flags->width-- - point + 1) && flags->minus)
			 count += ft_putchar(' ');
	}
	else if (flags->width <= flags->point)
		while(point-- && *str)
			count += ft_putchar(*str++);

	return (count);

}
