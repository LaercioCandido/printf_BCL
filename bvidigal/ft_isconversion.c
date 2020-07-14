/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconversion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:28:49 by bvidigal          #+#    #+#             */
/*   Updated: 2020/01/01 16:28:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isconversion(t_flags &flags, va_list args)
{
    int count;

    count = 0;
    if (flags->type == 'c' || flags->type == 's' || flags->type == 'd'
        || flags->type == 'i' || flags->type == 'i' || flags->type == 'x'
         || flags->type == 'X' || flags->type == 'p' || flags->type == 'u')
    {
        if (flags->type == 'd' || flags->type == 'i')
            count += ft_printf_d(flags, args);
        if (flags->type == 'x' || flags->type == 'X')
            count += ft_printf_x(flags, args);
        if (flags->type == 'c' || flags->type == 's')
            count += flags->type == 'c' ? ft_printf_c(flags, args) : ft_printf_s(flags, args);
        // if (flags->type == 'p')
        //     count += ft_printf_p(&flags, args);
    }
    return (count);
}
