/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:28:49 by bvidigal          #+#    #+#             */
/*   Updated: 2020/01/01 16:28:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_printf_star(t_flags *flags, va_list args)
{
    if (flags->star == 1)
		flags->width = va_arg(args, int);
	else if (flags->star == 2)
		flags->point = va_arg(args, int);
	else if (flags->star == 3)
    {
		flags->width = va_arg(args, int);
		flags->point = va_arg(args, int);
	}
}

int ft_printf_flags(t_flags *flags, va_list args)
{
    int count;
    char c;

	c = va_arg(args, int);
    count = 0;
    while (flags->width-- > 1)
        count += ft_putchar(' ');
    count += ft_putchar(c);
    return (count);
}


int ft_printf_minus(t_flags *flags, va_list args)
{
    int count;
    char c;

    c = va_arg(args, int);
    count = 0;
    count += ft_putchar(c);
    while (flags->width-- > 1)
        count += ft_putchar(' ');
    return (count);
}
