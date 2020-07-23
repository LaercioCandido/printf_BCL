/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:47:04 by bvidigal          #+#    #+#             */
/*   Updated: 2020/07/14 23:47:04 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	nbstrlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	*substring;

	total = nbstrlen(s1) + nbstrlen(s2) + 1;
	substring = (char *)malloc(total * sizeof(char));
	if (!substring)
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		substring[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		substring[i + j] = s2[j];
		j++;
	}
	substring[i + j] = '\0';
	return (substring);
}

char	*ft_strdup(const char *s1)
{
	size_t			len;
	char			*cpy;
	unsigned int	i;

	len = ft_strlen(s1) + 1;
	if (!(cpy = malloc(sizeof(char) * len)))
		return (0);
	i = 0;
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}

int	ft_printf_p(t_flags *flags, va_list args)
{
	int     count;
	void	*dec;
	int		len;
	char 	*number;

	ft_printf_star(flags, args);
	dec = va_arg(args, void *);
	number = dec == 0 ? ft_strdup("(nil)") : ft_itoa_base((unsigned long int)(dec), flags->type);
	count = 0;
	len = 12;// ft_strlen(number);
	if(flags->point == 0 && dec == 0)
		return (count);
	if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += dec == 0 ? ft_putstr(number) : ft_printf("0x") + ft_putstr(number);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_printf_pa(flags, len, number, dec);
	else if (flags->width >= len && len > flags->point)
		count += ft_printf_pb(flags, len, number, dec);
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_pc(flags, len, number, dec);
	free(number);
	return (count);
}
