/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilsx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcandido <lcandido@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:16:11 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/18 22:04:52 by lcandido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putflags(int condition, char c)
{
	int count;

	count = 0;
	while (condition--)
		count += ft_putchar(c);
	return (count);
}

//int	ft_printf_utils_xa()
