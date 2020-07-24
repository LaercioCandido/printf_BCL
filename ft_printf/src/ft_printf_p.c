/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/23 21:43:06 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printf_pa(t_flags *flags)
{
	int	count;

	count = 0;
	while (flags->width-- - 2 > 0)
		count += ft_putchar(' ');
	count += ft_printf("0x");
	return (count);
}

static int	ft_printf_pb(t_flags *flags, int len, char *end_hex)
{
	int	count;

	count = ft_printf("0x");
	while (flags->point-- - len)
		count += ft_putchar('0');
	count += ft_printf(end_hex);
	return (count);
}

static int	ft_printf_pc(t_flags *flags, int len, char *end_hex)
{
	int	count;

	count = 0;
	len = len + 2;
	if (flags->minus == 0)
	{
		while (flags->width-- - len > 0)
			count += (flags->zero && flags->point == -1)
				? ft_putchar('0') : ft_putchar(' ');
		count += ft_printf("0x%s", end_hex);
	}
	else
	{
		count += ft_printf("0x%s", end_hex);
		while (flags->width-- - len > 0)
			count += ft_putchar(' ');
	}
	return (count);
}

static int	ft_printf_pd(t_flags *flags, int len, char *end_hex)
{
	int	count;
	int	point;

	count = 0;
	point = flags->point;
	if (flags->minus == 0)
		while (flags->width-- - point)
			count += ft_putchar(' ');
	count += ft_printf("0x");
	while (flags->point-- - len)
		count += ft_putchar('0');
	count += ft_printf(end_hex);
	if (flags->minus == 1)
		while (flags->width-- - point)
			count += ft_putchar(' ');
	return (count);
}

int			ft_printf_p(t_flags *flags, va_list args)
{
	int						count;
	int						len;
	char					*end_hex;
	unsigned long int		end_dec;

	ft_printf_star(flags, args);
	end_dec = va_arg(args, unsigned long int);
	end_hex = ft_itoa_base(end_dec, 'x');
	count = 0;
	len = ft_strlen(end_hex);
	if (flags->point == 0 && end_dec == 0)
		count += ft_printf_pa(flags);
	else if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_printf("0x%s", end_hex);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_printf_pb(flags, len, end_hex);
	else if (flags->width >= len && len > flags->point)
		count += ft_printf_pc(flags, len, end_hex);
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_pd(flags, len, end_hex);
	free(end_hex);
	return (count);
}
