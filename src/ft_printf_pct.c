/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
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
