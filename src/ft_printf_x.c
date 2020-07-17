/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
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
    return (i);
}

int    digitcounter(unsigned long int n)
{
    if (!(n / 16))
        return (1);
    else
        return (digitcounter(n / 16) + 1);
}

char    *ft_itoa_base(unsigned long int n, char type)
//char    *ft_itoa_base(void *n, char type)
{
    char    *hexnumber;
    int        len;
    char    *base;


    base = type == 'X' ? "0123456789ABCDEF": "0123456789abcdef";
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

	ft_printf_star(flags, args);
	dec = va_arg(args, int);
	number = ft_itoa_base((unsigned int)dec, flags->type);
	count = 0;
	len = ft_strlen(number);
	if(flags->point == 0 && dec == 0)
		return (count);
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_putstr(number);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_printf_xa(flags->point, len, '0', number);
	else if (flags->width >= len && len > flags->point)
			count += ft_printf_xb(flags, len, number);
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_xc(flags, len, number);
	free(number);
	return (count);
}
