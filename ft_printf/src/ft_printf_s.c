/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 22:49:43 by camilo           ###   ########.fr       */
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
		count += ft_printf_sa(flags, len, str);
	else if (flags->width > flags->point)
		count += ft_printf_sb(flags, point, str);
	else if (flags->width <= flags->point)
		count += ft_printf_sc(flags, len, point, str);
	return (count);
}
