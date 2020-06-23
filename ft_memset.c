/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:00:49 by bvidigal          #+#    #+#             */
/*   Updated: 2020/05/05 23:01:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	if (len > 0)
	{
		while (len--)
		{
			*(unsigned char *)(dest + len) = (unsigned char)(c);
		}
	}
	return (dest);
}
