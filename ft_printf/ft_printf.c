/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:23:38 by lcandido          #+#    #+#             */
/*   Updated: 2020/06/23 19:23:38 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_flags{
	int		minus;
	int		zero;
	int		star;
	int		point;
	int		width;
	int		len;
	char	type;
} t_flags;

void    init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->star = 0; // 1 para largura / 2 para precisao / 3 printa valor do argumento (quando point == -2)
	flags->point = -1;
	flags->width = 0;
	flags->len = 0;
	flags->type = '\0';
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned	i;

	if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
	}
	else
		i = n;
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}

int	ft_isnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void checkflag(const char f, t_flags *flags)
{
	if (f == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	if (f == '0' && flags->minus != 1 && flags->width == 0)
		flags->zero = 1;
	if (f == '.')
	{
		flags->point = (flags->point == -1) ? 0 : -2;
	}
	if (f == '*')
	{
		if (flags->point == -1)
			flags->star = 1;
		else
			flags->star = (flags->star == 0) ? 2 : 3;
	}
}

int readflag(t_flags *flags, const char *str)
{
	int i;

	i = 0;
	while(str[i] == '-' || str[i] == '*' || str[i] == '.' || ft_isnum(str[i]))
	{
		checkflag(str[i], flags);
		if (ft_isnum(str[i]))
			while (ft_isnum(str[i]))
			{
				if (flags->point == -1)
					flags->width = (flags->width * 10) + (str[i] - '0');
				if (flags->point >= 0)
					flags->point = (flags->point * 10) + (str[i] - '0');
				i++;
			}
		else
		  i++; //esse i++ dá pau?
	}
	flags->type = str[i];
	flags->len = i;
	return (i);
}

int ft_numlen(int num)
{
	int i;

	i = 1;
	if (num < 0)
		i++;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int ft_printf_d(t_flags *flags, int number)
{
	int len;
	//int point;

	len = ft_numlen(number);

	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		ft_putnbr(number);
	else if (flags->point > flags->len && flags->point >= flags->width)
	{
		if (number < 0)
		{
			number = number * (-1);
			flags->point++;
			ft_putchar('-');
		}
		while (flags->point-- - len)
			ft_putchar('0');
		ft_putnbr(number);
	}
	else if (flags->width >= flags->len && flags->len > flags->point)
	{
		if (flags->minus == 0)
		{
			while (flags->width-- - len)
				ft_putchar(' ');
			ft_putnbr(number);
		}
		else
		{
			ft_putnbr(number);
			while (flags->width-- - len)
				ft_putchar(' ');
		}

	}
	else if (flags->width > flags->point && flags->point >= len)
	{
		if (flags->minus == 0)
			while (flags->width-- - flags->point + 1)
				ft_putchar(' ');
		if (number < 0)
		{
			ft_putnbr('-');
			number = number * (-1);
			len--;
		}
		while (flags->point-- - len)
			ft_putchar('0');
		ft_putnbr(number);
		if (flags->minus == 1)
			while (flags->width-- - flags->point)
				ft_putchar(' ');
	}
}

int ft_printf(const char *str, ...)
{
	int     count;
	va_list args;
	//int     number;
	t_flags flags;

		count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			init(&flags);
			str++;
			readflag(&flags, str);
			/*
			printf("\nminus = %d\n",flags.minus);
			printf("point = %d\n",flags.point);
			printf("star = %d\n",flags.star);
			printf("width = %d\n",flags.width);
			printf("zero = %d\n",flags.zero);
			printf("type = %c\n",flags.type);
			printf("len = %d\n",flags.len);
			*/
			if (flags.type == 'd')
			{
				ft_printf_d(&flags, va_arg(args, int));
			//  number = va_arg(args, int);
			//  ft_putnbr(number);
				str = str + flags.len; /////
			}
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
		count++;
	}
	return (count);
}

int main()
{
	//numeros negativos

	printf("teste%1.3dteste\n", -65432);
    printf("teste%01.3dteste\n", -65432);
    printf("teste%-1.3dteste\n", -65432);
    printf("teste%0-1.3dteste\n", -65432);
    printf("teste%-01.3dteste\n", -65432);
    printf("\n");

	ft_printf("teste%1.3dteste\n", -65432);
    ft_printf("teste%01.3dteste\n", -65432);
    ft_printf("teste%-1.3dteste\n", -65432);
    ft_printf("teste%0-1.3dteste\n", -65432);
    ft_printf("teste%-01.3dteste\n", -65432);
    ft_printf("\n---------------------------\n");

    printf("teste%3.1dteste\n", -65432);
    printf("teste%03.1dteste\n", -65432);
    printf("teste%-3.1dteste\n", -65432);
    printf("teste%0-3.1dteste\n", -65432);
    printf("teste%-03.1dteste\n", -65432);
    printf("\n");

	ft_printf("teste%3.1dteste\n", -65432);
    ft_printf("teste%03.1dteste\n", -65432);
    ft_printf("teste%-3.1dteste\n", -65432);
    ft_printf("teste%0-3.1dteste\n", -65432);
    ft_printf("teste%-03.1dteste\n", -65432);
    ft_printf("\n---------------------------\n");

    printf("teste%1.5dteste\n", -654);
    printf("teste%01.5dteste\n", -654);
    printf("teste%-1.5dteste\n", -654);
    printf("teste%0-1.5dteste\n", -654);
    printf("teste%-01.5dteste\n", -654);
    printf("\n");

	ft_printf("teste%1.5dteste\n", -654);
    ft_printf("teste%01.5dteste\n", -654);
    ft_printf("teste%-1.5dteste\n", -654);
    ft_printf("teste%0-1.5dteste\n", -654);
    ft_printf("teste%-01.5dteste\n", -654);
    ft_printf("\n---------------------------\n");

    printf("teste%3.5dteste\n", -6);
    printf("teste%03.5dteste\n", -6);
    printf("teste%-3.5dteste\n", -6);
    printf("teste%0-3.5dteste\n", -6);
    printf("teste%-03.5dteste\n", -6);
    printf("\n");

	ft_printf("teste%3.5dteste\n", -6);
    ft_printf("teste%03.5dteste\n", -6);
    ft_printf("teste%-3.5dteste\n", -6);
    ft_printf("teste%0-3.5dteste\n", -6);
    ft_printf("teste%-03.5dteste\n", -6);
    ft_printf("\n---------------------------\n");

    printf("teste%5.1dteste\n", -65);
    printf("teste%05.1dteste\n", -65);
    printf("teste%-5.1dteste\n", -65);
    printf("teste%0-5.1dteste\n", -65);
    printf("teste%-05.1dteste\n", -65);
    printf("\n");

	ft_printf("teste%5.1dteste\n", -65);
    ft_printf("teste%05.1dteste\n", -65);
    ft_printf("teste%-5.1dteste\n", -65);
    ft_printf("teste%0-5.1dteste\n", -65);
    ft_printf("teste%-05.1dteste\n", -65);
    ft_printf("\n---------------------------\n");

    printf("teste%5.3dteste\n", -6);
    printf("teste%05.3dteste\n", -6);
    printf("teste%-5.3dteste\n", -6);
    printf("teste%0-5.3dteste\n", -6);
    printf("teste%-05.3dteste\n", -6);
    printf("\n");

	ft_printf("teste%5.3dteste\n", -6);/*
    ft_printf("teste%05.3dteste\n", -6);
    ft_printf("teste%-5.3dteste\n", -6);
    ft_printf("teste%0-5.3dteste\n", -6);
    ft_printf("teste%-05.3dteste\n", -6);
    ft_printf("\n");
	*/






	//numeros positivos
	/*
	printf("teste%1.3dteste\n", 65432);
	printf("teste%01.3dteste\n", 65432);
    printf("teste%-1.3dteste\n", 65432);
    printf("teste%0-1.3dteste\n", 65432);
    printf("teste%-01.3dteste\n", 65432);
	printf("1\n");

	ft_printf("teste%1.3dteste\n", 65432);
	ft_printf("teste%01.3dteste\n", 65432);
	ft_printf("teste%-1.3dteste\n", 65432);
	ft_printf("teste%0-1.3dteste\n", 65432);
	ft_printf("teste%-01.3dteste\n", 65432);
    ft_printf("\n---------------------------\n");

    printf("teste%3.1dteste\n", 65432);
    printf("teste%03.1dteste\n", 65432);
    printf("teste%-3.1dteste\n", 65432);
    printf("teste%0-3.1dteste\n", 65432);
    printf("teste%-03.1dteste\n", 65432);
    printf("2\n");

	ft_printf("teste%3.1dteste\n", 65432);
    ft_printf("teste%03.1dteste\n", 65432);
    ft_printf("teste%-3.1dteste\n", 65432);
    ft_printf("teste%0-3.1dteste\n", 65432);
    ft_printf("teste%-03.1dteste\n", 65432);
    ft_printf("\n---------------------------\n");

    printf("teste%1.5dteste\n", 654);
    printf("teste%01.5dteste\n", 654);
    printf("teste%-1.5dteste\n", 654);
    printf("teste%0-1.5dteste\n", 654);
    printf("teste%-01.5dteste\n", 654);
    printf("3\n");

	ft_printf("teste%1.5dteste\n", 654);
    ft_printf("teste%01.5dteste\n", 654);
    ft_printf("teste%-1.5dteste\n", 654);
    ft_printf("teste%0-1.5dteste\n", 654);
    ft_printf("teste%-01.5dteste\n", 654);
    ft_printf("\n---------------------------\n");

    printf("teste%3.5dteste\n", 6);
    printf("teste%03.5dteste\n", 6);
    printf("teste%-3.5dteste\n", 6);
    printf("teste%0-3.5dteste\n", 6);
    printf("teste%-03.5dteste\n", 6);
    printf("4\n");

	ft_printf("teste%3.5dteste\n", 6);
    ft_printf("teste%03.5dteste\n", 6);
    ft_printf("teste%-3.5dteste\n", 6);
    ft_printf("teste%0-3.5dteste\n", 6);
    ft_printf("teste%-03.5dteste\n", 6);
    ft_printf("\n---------------------------\n");

    printf("teste%5.1dteste\n", 65);
    printf("teste%05.1dteste\n", 65);
    printf("teste%-5.1dteste\n", 65);
    printf("teste%0-5.1dteste\n", 65);
    printf("teste%-05.1dteste\n", 65);
    printf("5\n");

	ft_printf("teste%5.1dteste\n", 65);
    ft_printf("teste%05.1dteste\n", 65);
    ft_printf("teste%-5.1dteste\n", 65);
    ft_printf("teste%0-5.1dteste\n", 65);
    ft_printf("teste%-05.1dteste\n", 65);
    ft_printf("\n---------------------------\n");

    printf("teste%5.3dteste\n", 6);
    printf("teste%05.3dteste\n", 6);
    printf("teste%-5.3dteste\n", 6);
    printf("teste%0-5.3dteste\n", 6);
    printf("teste%-05.3dteste\n", 6);
    printf("6\n");

	ft_printf("teste%5.3dteste\n", 6);
    ft_printf("teste%05.3dteste\n", 6);
    ft_printf("teste%-5.3dteste\n", 6);
    ft_printf("teste%0-5.3dteste\n", 6);
    ft_printf("teste%-05.3dteste\n", 6);
    ft_printf("\n");
	*/


	return (0);
}
