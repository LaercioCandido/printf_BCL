/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:23:10 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/11 20:58:06 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	nbstrlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	*substring;

	total = nbstrlen(s1) + nbstrlen(s2) + 1;
	substring = (char *)malloc(total * sizeof(char));
	if (!substring)
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		substring[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		substring[i + j] = s2[j];
		j++;
	}
	substring[i + j] = '\0';
	return (substring);
}

int	ft_printf_p(t_flags *flags, va_list args)
{
	int     count;
	void	*dec;
	int		len;
	void 	*number;
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
	dec = va_arg(args, void *);
	number = ft_itoa_base((unsigned long int)(dec), flags->type);
	number = ft_strjoin("0x", number);
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
