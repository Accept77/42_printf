/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:11:24 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/16 18:46:09 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numprint(int n, int flag2, int *flag)
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
	if (flag2 == 1)
		p[0]++;
	while (count >= 0)
	{
		*flag = write(1, &p[count], 1);
		if (*flag == -1)
			break ;
		count--;
	}
	if (flag2 > 0)
		return (ft_strlen(p) + 1);
	else
		return (ft_strlen(p));
}

int	ft_printnbr(int n, int *flag)
{
	int	flag2;
	int	count;

	flag2 = 0;
	if (n == 0)
	{
		*flag = write(1, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		flag2++;
		n++;
	}
	else if (0 > n && n > -2147483648)
		flag2 = 2;
	if (flag2 > 0)
	{
		n *= -1;
		*flag = write(1, "-", 1);
		if (*flag == -1)
			return (0);
	}
	count = numprint(n, flag2, flag);
	return (count);
}
