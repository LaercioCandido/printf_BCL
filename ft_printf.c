/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:28:49 by bvidigal          #+#    #+#             */
/*   Updated: 2020/01/01 16:28:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     ft_printf(const char *input, ...)
{
	int d;
	int valnum;
	int length;
	unsigned int x;
	char *s;
	unsigned long int p;
	//valnum tem que ser o atoi do input

	va_list args;
	va_start(args, input);
	while(*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			valnum = ft_atoi(input);
			if (*input == '%')
				ft_putchar(*input);
			if (*input == '+')
			{
				input++;
				if (*input == 'd' || *input == 'i')
				{
					input++;
					d = va_arg(args, int);
					if (d >= 0)
						ft_putchar('+');
					ft_putnbr(d);
				}
				ft_putchar(*input);
			}
			if (*input == '.')
			{
				input++;
				/*valnum = ft_atoi(input);
				printf("valnum = %d\n", valnum);
				while (valnum >= 0)
				{
					ft_printf("valnum = %d\n", valnum);
					valnum--;
				}*/
				if (*input == 's')
				{
					input++;
					ft_putchar(*input);
				}
			}
			if (*input == '-')
			{
				input++;
				valnum = ft_atoi(input);
				while (ft_isnum(*input))
					input++;
				if (*input == 'd' || *input == 'i')
				{
					input++;
					d = va_arg(args, int);
					ft_putnbr(d);
				}
				if (d < 0)
					valnum--;
				if (*input == 'c')
				{
					input++;
					ft_putchar((char)va_arg(args, int));
				}
				if (*input == 's')
				{
					input++;
					s = va_arg(args, char *);
					if (s == 0)
						ft_printf("(null)");
					else
						ft_printf(s);
				}
				length = ft_strlen(s);
				while (length >= 0)
				{
				length--;
				valnum--;
				}
				while (valnum > 1 && *input++ != '%')
				{
					ft_putchar(' ');
					valnum--;
				}
				ft_putchar(*input);

			}
			if (*input == '0')
			{
				input++;
				valnum = ft_atoi(input);
				while(ft_isnum(*input))
					input++;
				while (valnum > 1)
				{
					valnum--;
					ft_putchar('0');
				}

			}
			if (ft_isnum(*input) && *input != '0')
			{
				while (ft_isnum(*input) && *input != '0')
					input++;
				if (*input == '%')
					ft_putchar('%');
				if(*input == '.')
				{
					input++;
					valnum = ft_atoi(input);
					s = va_arg(args, char *);
					d = 0;
					while (valnum > 0 && *s != '\0')
					{
						ft_putchar(s[d]);
						valnum--;
						d++;
					}
					input++;
					if (*input == 's')
					{
						input++;
						ft_putchar(*input);
					}

				}
			}
			if (*input == 'd' || *input == 'i')
			{
				ft_putnbr(va_arg(args, int));
			}
			if (*input == 'c')
			{
				ft_putchar((char)va_arg(args, int));
			}
			if (*input == 's')
			{
				s = va_arg(args, char *);
				if (s == 0)
					ft_printf("(null)");
				else
					ft_printf(s);
			}
			if (*input == 'x')
			{
				x = va_arg(args, unsigned int);
				ft_puthex(x);
			}
			if (*input == 'X')
			{
				x = va_arg(args, unsigned int);
				ft_puthex(x);
			}
			if (*input == 'p')
			{
				p = va_arg(args, unsigned long int);
				if (p == 0)
					ft_printf("(nil)");
				else
				{
					ft_printf("0x");
					ft_puthex(p);
				}
			}
			if (*input == 'u')
			{
				x = va_arg(args, unsigned int);
				ft_putnbr(x);
			}
		}
		else
			ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (0);
}
