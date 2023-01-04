/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:51 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/04 17:48:53 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_turn_hex(unsigned long long i)
{
	const char	*hex;
	char		p[17];
	int			count;

	hex = "0123456789abcdef";
	count = 0;
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i != 0)
	{
		p[count] = hex[i % 16];
		i /= 16;
		count++;
	}
	p[count] = '\0';
	while (--count >= 0)
		write(1, &p[count], 1);
	return (ft_strlen(p));
}

int	ft_printaddress(void *addr)
{
	unsigned long long	i;
	int					count;

	count = 0;
	i = (unsigned long long)addr;
	write(1, "0x", 2);
	count = ft_turn_hex(i);
	count += 2;
	return (count);
}
