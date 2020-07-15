/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:49:18 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/15 19:20:49 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_pct(t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus)
		count += ft_putchar('%');
	while (flags->width-- > 1)
		count += flags->zero ? ft_putchar('0') : ft_putchar(' ');
	if (!flags->minus)
		count+= ft_putchar('%');
	return (count);
}
