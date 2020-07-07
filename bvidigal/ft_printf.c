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

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	unsigned	i;
	int 		count;

	count = 1;
	if (n < 0)
	{
		count += ft_putchar('-');
		i = n * -1;
	}
	else
		i = n;
	if (i >= 10)
		ft_putnbr(i / 10);
	count += ft_putchar(i % 10 + 48);
	return (count);
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
		// if (flags->point == 0)
		// 	flags->point = -2;
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

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int ft_printf_d(t_flags *flags, va_list args)
{
	int len;
	int point;
	int	number;
	int count;

	if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
	{
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
	number = va_arg(args, int);
	len = ft_numlen(number);
	count = 0;
	if(flags->point == 0 && number == 0) // qq isso aqui faz mesmo?
	{
		//ft_putchar('H');
		return (count);
	}
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_putnbr(number);
	else if (flags->point > len && flags->point >= flags->width)
	{
		if (number < 0)
		{
			number = number * (-1);
			flags->point++;
			count += ft_putchar('-');
		}
		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_putnbr(number);
	}
	else if (flags->width >= len && len > flags->point)
	{

		if (flags->minus == 0)
		{
			if (number < 0 && flags->point == -1)
			{
				number = number * (-1);
				flags->point++;
				count += ft_putchar('-');
				while (flags->width-- - len)
					count += flags->zero ? ft_putchar('0') : ft_putchar('H'); //esse tenario nao roda else
				count += ft_putnbr(number);
			}
			else if (number < 0)
			{
				while ((flags->point >= 0) && (flags->width-- - len))
					count += flags->zero ? ft_putchar(' ') : ft_putchar('0');
				count += ft_putnbr(number);
			}
			else
			{
				while (flags->width-- - len)
						count += flags->point == -2 ? ft_putchar('B') : ft_putchar('Q');//
				count += ft_putnbr(number);
			}


		}
		else
		{
			count += ft_putnbr(number);
			while (flags->width-- - len)
				count += ft_putchar(' ');
		}

	}
	else if (flags->width > flags->point && flags->point >= len)
	{
		point = number < 0? flags->point + 1: flags->point;
		if (flags->minus == 0)
			while (flags->width-- - point)
				count += ft_putchar(' '); //removi tenario aqui
		if (number < 0)
		{
			count += ft_putchar('-');
			number = number * (-1);
			len--;
		}

		while (flags->point-- - len)
			count += ft_putchar('0');
		count += ft_putnbr(number);
		if (flags->minus == 1)
			while (flags->width-- - point)
				count += ft_putchar(' ');
	}
	return (count);
}

int ft_printf_c(t_flags *flags, va_list args)
{
	int count;
	char c;
	c = va_arg(args, int);
	count = 0;
	if (flags->minus == 1)
	{
		count += ft_putchar(c);
		while (flags->width-- > 1)
			count += ft_putchar(' ');
	}
	// else if (flags->zero == 1)
	// {
	// 	while (flags->width-- > 1)
	// 		count += ft_putchar(' ');
	// 	count += ft_putchar(c);
	// }
	else
	{
		while (flags->width-- > 1)
			count += ft_putchar(' ');
		count += ft_putchar(c);
	}
	return (count);
}

int	ft_printf_s(t_flags *flags, va_list args)
{
	int count;
	char *str;
	int len;

	str = va_arg(args, char *);
	// printf("\n%s<<<<\n", str);
	// return (0);
	len = ft_strlen(str);
	count = 0;
	if (flags->len == 0 || (flags->point == -1 && len >= flags->width) )
		while(*str)
			count += ft_putchar(*str++);
	else if (flags->width > flags->point)
	{
		while((flags->width - count) && !(flags->minus))
		 	count += ft_putchar('*');
		while(flags->point--)
		{
			count += ft_putchar(*str++);
		}
		while((flags->width - count) && flags->minus)
			 count += ft_putchar('*');
	}


	return (count);

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
			if (flags.type == 'd' || flags.type == 'i')
			{
				ft_printf_d(&flags, args);
			//  number = va_arg(args, int);
			//  ft_putnbr(number);
				str = str + flags.len; /////
			}
			if (flags.type == 'c')
			{
				ft_printf_c(&flags, args);
			//  number = va_arg(args, int);
			//  ft_putnbr(number);
				str = str + flags.len; /////
			}
			if (flags.type == 's')
			{
				ft_printf_s(&flags, args);
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
    //printf("teste%01.3dteste\n", -65432);
    printf("teste%-1.3dteste\n", -65432);
    //printf("teste%0-1.3dteste\n", -65432);
    //printf("teste%-01.3dteste\n", -65432);
    printf("1\n");

	ft_printf("teste%1.3dteste\n", -65432);
    ft_printf("teste%01.3dteste\n", -65432);
    ft_printf("teste%-1.3dteste\n", -65432);
    ft_printf("teste%0-1.3dteste\n", -65432);
    ft_printf("teste%-01.3dteste\n", -65432);
    ft_printf("\n---------------------------\n");

    printf("teste%3.1dteste\n", -65432);
    //printf("teste%03.1dteste\n", -65432);
    printf("teste%-3.1dteste\n", -65432);
    //printf("teste%0-3.1dteste\n", -65432);
    //printf("teste%-03.1dteste\n", -65432);
    printf("2\n");

	ft_printf("teste%3.1dteste\n", -65432);
    ft_printf("teste%03.1dteste\n", -65432);
    ft_printf("teste%-3.1dteste\n", -65432);
    ft_printf("teste%0-3.1dteste\n", -65432);
    ft_printf("teste%-03.1dteste\n", -65432);
    ft_printf("\n---------------------------\n");

    printf("teste%1.5dteste\n", -654);
    //printf("teste%01.5dteste\n", -654);
    printf("teste%-1.5dteste\n", -654);
    //printf("teste%0-1.5dteste\n", -654);
    //printf("teste%-01.5dteste\n", -654);
    printf("3\n");

	ft_printf("teste%1.5dteste\n", -654);
    ft_printf("teste%01.5dteste\n", -654);
    ft_printf("teste%-1.5dteste\n", -654);
    ft_printf("teste%0-1.5dteste\n", -654);
    ft_printf("teste%-01.5dteste\n", -654);
    ft_printf("\n---------------------------\n");

    printf("teste%3.5dteste\n", -6);
    //printf("teste%03.5dteste\n", -6);
    printf("teste%-3.5dteste\n", -6);
    //printf("teste%0-3.5dteste\n", -6);
    //printf("teste%-03.5dteste\n", -6);
    printf("4\n");

	ft_printf("teste%3.5dteste\n", -6);
    ft_printf("teste%03.5dteste\n", -6);
    ft_printf("teste%-3.5dteste\n", -6);
    ft_printf("teste%0-3.5dteste\n", -6);
    ft_printf("teste%-03.5dteste\n", -6);
    ft_printf("\n---------------------------\n");

    printf("teste%5.1dteste\n", -65);
    //printf("teste%05.1dteste\n", -65);
    printf("teste%-5.1dteste\n", -65);
    //printf("teste%0-5.1dteste\n", -65);
    //printf("teste%-05.1dteste\n", -65);
    printf("5\n");

	ft_printf("teste%5.1dteste\n", -65);
    ft_printf("teste%05.1dteste\n", -65);
    ft_printf("teste%-5.1dteste\n", -65);
    ft_printf("teste%0-5.1dteste\n", -65);
    ft_printf("teste%-05.1dteste\n", -65);
    ft_printf("\n---------------------------\n");

    printf("teste%5.3dteste\n", -6);
    //printf("teste%05.3dteste\n", -6);
    printf("teste%-5.3dteste\n", -6);
    //printf("teste%0-5.3dteste\n", -6);
    //printf("teste%-05.3dteste\n", -6);
    printf("6\n");

	ft_printf("teste%5.3dteste\n", -6);
    ft_printf("teste%05.3dteste\n", -6);
    ft_printf("teste%-5.3dteste\n", -6);
    ft_printf("teste%0-5.3dteste\n", -6);
    ft_printf("teste%-05.3dteste\n", -6);
    ft_printf("\n");






	//numeros positivos

	printf("teste%1.3dteste\n", 65432);
	//printf("teste%01.3dteste\n", 65432);
    printf("teste%-1.3dteste\n", 65432);
    //printf("teste%0-1.3dteste\n", 65432);
    //printf("teste%-01.3dteste\n", 65432);
	printf("7\n");

	ft_printf("teste%1.3dteste\n", 65432);
	ft_printf("teste%01.3dteste\n", 65432);
	ft_printf("teste%-1.3dteste\n", 65432);
	ft_printf("teste%0-1.3dteste\n", 65432);
	ft_printf("teste%-01.3dteste\n", 65432);
    ft_printf("\n---------------------------\n");

    printf("teste%3.1dteste\n", 65432);
    //printf("teste%03.1dteste\n", 65432);
    printf("teste%-3.1dteste\n", 65432);
    //printf("teste%0-3.1dteste\n", 65432);
    //printf("teste%-03.1dteste\n", 65432);
    printf("8\n");

	ft_printf("teste%3.1dteste\n", 65432);
    ft_printf("teste%03.1dteste\n", 65432);
    ft_printf("teste%-3.1dteste\n", 65432);
    ft_printf("teste%0-3.1dteste\n", 65432);
    ft_printf("teste%-03.1dteste\n", 65432);
    ft_printf("\n---------------------------\n");

    printf("teste%1.5dteste\n", 654);
    //printf("teste%01.5dteste\n", 654);
    printf("teste%-1.5dteste\n", 654);
    //printf("teste%0-1.5dteste\n", 654);
    //printf("teste%-01.5dteste\n", 654);
    printf("9\n");

	ft_printf("teste%1.5dteste\n", 654);
    ft_printf("teste%01.5dteste\n", 654);
    ft_printf("teste%-1.5dteste\n", 654);
    ft_printf("teste%0-1.5dteste\n", 654);
    ft_printf("teste%-01.5dteste\n", 654);
    ft_printf("\n---------------------------\n");

    //printf("teste%3.5dteste\n", 6);
    //printf("teste%03.5dteste\n", 6);
    printf("teste%-3.5dteste\n", 6);
    //printf("teste%0-3.5dteste\n", 6);
    //printf("teste%-03.5dteste\n", 6);
    printf("10\n");

	ft_printf("teste%3.5dteste\n", 6);
    ft_printf("teste%03.5dteste\n", 6);
    ft_printf("teste%-3.5dteste\n", 6);
    ft_printf("teste%0-3.5dteste\n", 6);
    ft_printf("teste%-03.5dteste\n", 6);
    ft_printf("\n---------------------------\n");

    printf("teste%5.1dteste\n", 65);
    //printf("teste%05.1dteste\n", 65);
    printf("teste%-5.1dteste\n", 65);
    //printf("teste%0-5.1dteste\n", 65);
    //printf("teste%-05.1dteste\n", 65);
    printf("11\n");

	ft_printf("teste%5.1dteste\n", 65);
    ft_printf("teste%05.1dteste\n", 65);
    ft_printf("teste%-5.1dteste\n", 65);
    ft_printf("teste%0-5.1dteste\n", 65);
    ft_printf("teste%-05.1dteste\n", 65);
    ft_printf("\n---------------------------\n");

    printf("teste%5.3dteste\n", 6);
    //printf("teste%05.3dteste\n", 6);
    printf("teste%-5.3dteste\n", 6);
    //printf("teste%0-5.3dteste\n", 6);
    //printf("teste%-05.3dteste\n", 6);
    printf("12\n");

	ft_printf("teste%5.3dteste\n", 6);
    ft_printf("teste%05.3dteste\n", 6);
    ft_printf("teste%-5.3dteste\n", 6);
    ft_printf("teste%0-5.3dteste\n", 6);
    ft_printf("teste%-05.3dteste\n", 6);
    ft_printf("\n-----------------------------\n");

	printf("teste%.0dteste\n", 0);
    //printf("teste%0.0dteste\n", 0);
    printf("teste%-5dteste\n", 0);
    //printf("teste%0-5dteste\n", 0);
    //printf("teste%-05dteste\n", 0);
    printf("13\n");

	ft_printf("teste%.0dteste\n", 0);
    ft_printf("teste%0.0dteste\n", 0);
    ft_printf("teste%-5dteste\n", 0);
    ft_printf("teste%0-5dteste\n", 0);
    ft_printf("teste%-05dteste\n", 0);
    ft_printf("\n");

	ft_printf("\n-----------------------------\n");

	printf("teste%*dteste\n", 3, 5);
    printf("teste%*.dteste\n", 3, 5);
    //printf("teste%0.*dteste\n", 3, 5);
    printf("teste%*dteste\n", 3, 5);
    printf("teste%*.*dteste\n", 3, 1, 2);
    printf("14\n");

	ft_printf("teste%*dteste\n", 3, 5);
    ft_printf("teste%*.dteste\n", 3, 5);
    ft_printf("teste%0.*dteste\n", 3, 5);
    ft_printf("teste%*dteste\n", 3, 5);
    ft_printf("teste%*.*dteste\n", 3, 1, 2);
    ft_printf("\n");

	ft_printf("\n-----------------------------\n");

	printf("teste%.0dteste\n", 1);
	//printf("teste%0.0dteste\n", 1);
	printf("teste%0dteste\n", 7);
	printf("teste%.dteste\n", 1);
	//printf("teste%0.dteste\n", 1);
	printf("15\n");

	ft_printf("teste%.0dteste\n", 1);
	ft_printf("teste%0.0dteste\n", 1);
	ft_printf("teste%0dteste\n", 7);
	ft_printf("teste%.dteste\n", 1);
	ft_printf("teste%0.dteste\n", 1);
	ft_printf("\n");

	ft_printf("\n-----------------------------\n");

	printf("teste%05dteste\n", 1);
	//printf("teste%05.dteste\n", 2);
	//printf("teste%0.5dteste\n", 1);
	//printf("teste%05.2dteste\n", 1);
	//printf("teste%02.5dteste\n", 1);
	printf("16\n");

	ft_printf("teste%05dteste\n", 1);
	ft_printf("teste%05.dteste\n", 2);
	ft_printf("teste%0.5dteste\n", 1);
	ft_printf("teste%05.2dteste\n", 1);
	ft_printf("teste%02.5dteste\n", 1);
	ft_printf("\n");

	ft_printf("\n-----------------------------\n");

	printf("teste%05dteste\n", -1);
	//printf("teste%05.dteste\n", -1);
	//printf("teste%0.5dteste\n", -1);
	//printf("teste%05.2dteste\n", -1);
	printf("teste%5.2dteste\n", -1);
	//printf("teste%02.5dteste\n", -1);
	printf("17\n");

	ft_printf("teste%05dteste\n", -1);
	ft_printf("teste%05.dteste\n", -1);
	ft_printf("teste%0.5dteste\n", -1);
	ft_printf("teste%05.2dteste\n", -1);
	ft_printf("teste%5.2dteste\n", -1);
	ft_printf("teste%02.5dteste\n", -1);
	ft_printf("\n");

	ft_printf("\n-----------------------------\n");
	ft_printf("\n--------conversion c---------\n");
	ft_printf("\n-----------------------------\n");
	printf("teste%cteste\n", 'X');
	//printf("teste%0cteste\n", 'X');
	printf("teste%-cteste\n", 'X');
	//printf("teste%-0cteste\n", 'X');
	printf("teste%5cteste\n", 'X');
	printf("teste%cteste\n", 'X');
	printf("18\n");

	ft_printf("teste%cteste\n", 'X');
	ft_printf("teste%0cteste\n", 'X');
	ft_printf("teste%-cteste\n", 'X');
	ft_printf("teste%-0cteste\n", 'X');
	ft_printf("teste%5cteste\n", 'X');
	ft_printf("teste%cteste\n", 'X');
	ft_printf("\n");

	ft_printf("\n-----------------------------\n");


	//printf("teste%05cteste\n", 'X');
	//printf("teste%05.cteste\n", 'X');
	//printf("teste%0.5cteste\n", 'X');
	//printf("teste%05.2cteste\n", 'X');
	//printf("teste%5.2cteste\n", 'X');
	//printf("teste%02.5cteste\n", 'X');
	printf("19\n");

	ft_printf("teste%05cteste\n", 'X');
	ft_printf("teste%05.cteste\n", 'X');
	ft_printf("teste%0.5cteste\n", 'X');
	ft_printf("teste%05.2cteste\n", 'X');
	ft_printf("teste%5.2cteste\n", 'X');
	ft_printf("teste%02.5cteste\n", 'X');
	ft_printf("\n");

	ft_printf("\n-----------------------------\n");


	//printf("teste%-05cteste\n", 'a');
	//printf("teste%-05.cteste\n", 'a');
	//printf("teste%-0.5cteste\n", 'a');
	//printf("teste%-05.2cteste\n", 'a');
	//printf("teste%-5.2cteste\n", 'a');
	//printf("teste%-03.5cteste\n", 'a');
	printf("20\n");

	ft_printf("teste%-05cteste\n", 'a');
	ft_printf("teste%-05.cteste\n", 'a');
	ft_printf("teste%-0.5cteste\n", 'a');
	ft_printf("teste%-05.2cteste\n", 'a');
	ft_printf("teste%-5.2cteste\n", 'a');
	ft_printf("teste%-03.5cteste\n", 'a');
	ft_printf("\n");


	ft_printf("\n-----------------------------\n");
	ft_printf("\n--------conversion s---------\n");
	ft_printf("\n-----------------------------\n");
	printf("1%s\n", "teste");
	// printf("1%0s\n", "teste");
	printf("2%-s\n", "teste");
	// printf("1%-0s\n", "teste");
	printf("3%4sG\n", "teste");
	printf("3%4.4sG\n", "teste");
	printf("3%4.sG\n", "teste");
	printf("4%7sG\n", "teste");
	printf("4%-7sG\n", "teste");
	printf("5%4.3sG\n", "teste");
	printf("5%-4.3sG\n", "teste");
	printf("6%7.3sG\n", "teste");
	printf("6%-7.3sG\n", "teste");
	printf("7%7.10sG\n", "teste");
	printf("7%-7.10sG\n", "teste");
	//printf("8%0.5sG\n", "teste");
	printf("9%5.0sG\n", "teste");
	printf("9%-5.0sG\n", "teste");

	// printf("%07.10s\n", "teste");
	// printf("%-07.10s\n", "teste");
	printf("------------18\n");

	ft_printf("1%s\n", "teste");
	// ft_printf("1%0s\n", "teste");
	ft_printf("2%-s\n", "teste");
	// ft_printf("1%-0s\n", "teste");
	ft_printf("3%4sG\n", "teste");
	ft_printf("4%5sG\n", "teste");
	ft_printf("5%8.0sG\n", "teste");
	ft_printf("6%8.3sG\n", "teste");
	ft_printf("7%-8.0sG\n", "teste");
	ft_printf("8%-8.3sG\n", "teste");
	ft_printf("9%-8.sG\n", "teste");
	//ft_printf("10%8sG\n", "teste");
	ft_printf("\n");

	ft_printf("\n-----------------------------\n");


	return (0);
}
