/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;
	int		len;
	int		point;

	if (flags->star == 1)
    {
		if ((flags->width = va_arg(args, int)) < 0)
		{
			flags->width = flags->width * -1;
			flags->minus = 1;
		}
    }
	else if (flags->star == 2)
			flags->point = (flags->point = va_arg(args, int)) < 0 ? flags->point * -1 : flags->point;
	else if (flags->star == 3)
	{
		if ((flags->width = va_arg(args, int)) < 0)
		{
			flags->width = flags->width *  (-1);
			flags->minus = 1;
		}
		flags->point = (flags->point = va_arg(args, int)) < 0 ? flags->point * -1 : flags->point;
	}
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
		while ((len < flags->point--) && flags->width >= len && len)
			count += ft_putchar(' ');
		while (!len && flags->width-- && !flags->minus)
			count += ft_putchar(' ');
		while (point-- && *str)
			count += ft_putchar(*str++);
		while (flags->minus && flags->width-- && *str)
			count += ft_putchar(' ');
	}
	return (count);
}
