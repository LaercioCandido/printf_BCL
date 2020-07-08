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

	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	str = va_arg(args, char *);

	// printf("\n%s<<<<\n", str);
	// return (0);
	count = 0;
	if (str == NULL && flags->point < 6 && flags->point > -1)
		str = "";
	else if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);

	point = flags->point > len ? len : flags->point;
	if (flags->len == 0 || (flags->point == -1 && len >= flags->width))
		while(*str)
			count += ft_putchar(*str++);
	else if (flags->point == -1 && flags->width > len)
	{
		while((flags->width-- - len) && !(flags->minus))
			count += ft_putchar(' ');
		while(*str)
			count += ft_putchar(*str++);
		while((flags->width-- - len + 1) && flags->minus)
			count += ft_putchar(' ');
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
	{
		while((len < flags->point--) && flags->width >= len) //novo while agora funciona(?)
			count += ft_putchar(' ');
		while(point-- && *str)
			count += ft_putchar(*str++);
		while(flags->minus && flags->width--)
				count += ft_putchar(' ');
	}
	return (count);

}
