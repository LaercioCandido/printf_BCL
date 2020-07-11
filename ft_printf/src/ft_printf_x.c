/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/08 20:08:16 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int    digitcounter(unsigned int n)
{
    if (!(n / 16))
        return (1);
    else
        return (digitcounter(n / 16) + 1);
}

char    *ft_itoa_base(unsigned int n, char type)
{
    char    *hexnumber;
    int        len;
    char    *base;


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

int ft_printf_x(t_flags *flags, va_list args)
{
	int     count;
	int		dec;
	int		len;
	char 	*number;
	int 	point;

	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	dec = va_arg(args, int);
	number = ft_itoa_base(dec, flags->type);
	count = 0;
	len = ft_strlen(number);
	if(flags->point == 0 && dec == 0)
		return (count);
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
						count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
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
