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
    flags->star = 0; // 1 para largura / 2 para precisao / 3 printa valor do argumento (quando point == 1)
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
    flags->point = (flags->point == -1) ? 0 : 1;
    // if (flags.point == -1 )
    //   flags->point = 0;
    // else
    //   flags->point = 1;
  }
  if (f == '*')
  {
    if (flags->point == -1)
      flags->star = 1;
    else
      flags->star = (flags->point == 0) ? 2 : 3;
    
    // if(flags->point == 0)
    //   flags->star = 2;
    // if(flags->point == 1)
    //   flags->star = 3;
  }
}

int readflag(t_flags *flags, const char *str)
{
  int i;

  i = 0;
  while(str[i] == '-' || str[i] == '*' || str[i] == '.' || ft_isnum(str[i]))
  {
    checkflag(str[i], flags);
    while (ft_isnum(str[i]))
    {
        if (flags->point == 0)
            flags->width = (flags->width * 10) + (str[i] - '0');
        else
            flags->point = (flags->point * 10) + (str[i] - '0');
        i++;
    }
    i++; //esse i++ dá pau?
  }
  return (i);
}

int ft_printf(const char *str, ...)
{
    int     count;
    va_list args;
    int     number;
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
        count++;
    }
    return (count);
}

int main()
{
    ft_printf("camilo  %d  %d\n", 24, 42);
    return (0);
}