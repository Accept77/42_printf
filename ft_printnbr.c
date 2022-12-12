/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:11:24 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/12 16:11:10 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	numprint(int n, int flag)
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
	if (flag == 1)
		p[0]++;
	while (count >= 0)
	{
		write(1, &p[count], 1);
		count--;
	}
	if (flag > 0)
		return (ft_strlen(p) + 1);
	else
		return (ft_strlen(p));
}

int	ft_printnbr(int n)
{
	int	flag;
	int	count;

	flag = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		flag++;
		n++;
		n *= -1;
		write(1, "-", 1);
	}
	else if (0 > n && n > -2147483648)
	{
		flag = 2;
		n *= -1;
		write(1, "-", 1);
	}
	count = numprint(n, flag);
	return (count);
}
