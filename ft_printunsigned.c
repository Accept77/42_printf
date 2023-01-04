/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:22:40 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/04 17:49:34 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numprint(unsigned int n)
{
	char	p[11];
	int		count;

	count = 0;
	while (n != 0)
	{
		p[count] = n % 10 + '0';
		n /= 10;
		count++;
	}
	p[count] = '\0';
	--count;
	while (count >= 0)
	{
		write(1, &p[count], 1);
		count--;
	}
	return (ft_strlen(p));
}

int	ft_printunsigned(unsigned int n)
{
	int	count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = numprint(n);
	return (count);
}
