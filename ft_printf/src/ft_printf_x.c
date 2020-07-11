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
#include <stdio.h>

int		ft_putstr(char *s)
{
	unsigned int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

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
		count += ft_putstr(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_putstr(number);
	}
	else if (flags->width >= len && len > flags->point)
	{

			if (flags->minus == 0)
			{
				while (flags->width-- - len)
						count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
				count += ft_putstr(number);
			}
			else
			{
				count += ft_putstr(number);
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
			count += ft_putstr(number);
			if (flags->minus == 1)
				while (flags->width-- - point)
					count += ft_putchar(' ');
		}
	free(number);
	return (count);
}
