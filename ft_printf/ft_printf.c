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

typedef struct s_flags{
    int     minus;
    int     zero;
    int     star;
    int     point;
    int     width;
    int     len;
    char    type;
} t_flags;

void    init(t_flags *flags)
{
    flags->minus = 0;
    flags->zero = 0;
    flags->star = 0;
    flags->point = 0;
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


int ft_printf(const char *str, ...)
{
    int     i;
    va_list args;
    int     number;
    t_flags flags;

    i= 0;
    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            init(&flags);
            str++;
            readflag(&flags, str);
            if (*str == 'd')
            {
                number = va_arg(args, int);
                ft_putnbr(number);
            }
        }
        else
        {        
            ft_putchar(*str);
        }
        str++;
        i++;
    }
    return (i);
}

int main()
{
    ft_printf("camilo  %d  %d\n", 24, 42);
    return (0);
}