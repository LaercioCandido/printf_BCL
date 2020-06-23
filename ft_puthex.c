/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:00:49 by bvidigal          #+#    #+#             */
/*   Updated: 2020/05/05 23:01:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex(unsigned long int nb)
{
	char hex[16];
	int  tmp;
	int  i;

	ft_bzero(hex, 16);
	i = 0;
	while (nb)
	{
		tmp = nb % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('a' - 10) : '0'));
		nb /= 16;
		i++;
	}
	while (i >= 1)
	{
	i--;
	ft_putchar(hex[i]);
	}
}
