/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/15 19:30:35 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_printf_p(t_flags *flags, va_list args)
{
	int		count;
	unsigned long int		end_dec;
	int		len;
	char	*end_hex;
	int		point;

	ft_printf_star(flags, args);
	end_dec = va_arg(args, unsigned long int);
	end_hex = ft_itoa_base(end_dec, 'x');
	count = 0;
	len = ft_strlen(end_hex);
	if (flags->point == 0 && end_dec == 0)
		count += ft_printf_pa(flags);
	else if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_printf("0x%s", end_hex);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_printf_pb(flags, len, end_hex);
	else if (flags->width >= len && len > flags->point)
		count += ft_printf_pc(flags, len, end_hex);
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_pd(flags, len, end_hex);
	free(end_hex);
	return (count);
}
