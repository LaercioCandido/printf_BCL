/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/23 21:41:29 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_star(t_flags *flags, va_list args)
{
	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	if (flags->type == 'd' || flags->type == 'i' || flags->type == 's')
	{
		if (flags->width < 0)
		{
			flags->width = flags->width * -1;
			flags->minus = 1;
		}
		if (flags->point < 0)
			flags->point = -1;
	}
}

int		ft_isconversion(t_flags *flags, va_list args)
{
	int count;

	count = 0;
	if (flags->type == 'd' || flags->type == 'i')
		count += ft_printf_d(flags, args);
	if (flags->type == 'x' || flags->type == 'X')
		count += ft_printf_x(flags, args);
	if (flags->type == 'c')
		count += ft_printf_c(flags, args);
	if (flags->type == 's')
		count += ft_printf_s(flags, args);
	if (flags->type == 'p')
		count += ft_printf_p(flags, args);
	if (flags->type == 'u')
		count += ft_printf_u(flags, args);
	if (flags->type == '%')
		count += ft_printf_pct(flags);
	return (count);
}

int		ft_putflags(int condition, char c)
{
	int count;

	count = 0;
	while (condition-- > 0)
		count += ft_putchar(c);
	return (count);
}
