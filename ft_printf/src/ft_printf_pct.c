/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:49:18 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/14 18:26:21 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_pct(t_flags *flags)
{
	int		count;

	if (flags->minus)
		count += ft_putchar('%');
	while (flags->width-- > 1)
		count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
	if (!flags->minus)
		count+= ft_putchar('%');
	return (count);
}
