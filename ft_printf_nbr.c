/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:09:14 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/22 18:56:29 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_numprint(unsigned int n, int *flag)
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
		*flag = write(1, &p[count], 1);
		if (*flag == -1)
			break ;
		count--;
	}
	return (ft_strlen(p));
}

static int	numprint(int n, int what, int *flag)
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
	if (what == 1)
		p[0]++;
	while (count >= 0)
	{
		*flag = write(1, &p[count], 1);
		if (*flag == -1)
			break ;
		count--;
	}
	if (what > 0)
		return (ft_strlen(p) + 1);
	else
		return (ft_strlen(p));
}

int	ft_printnbr(int n, int *flag)
{
	int	what;
	int	count;

	what = 0;
	if (n == 0)
	{
		*flag = write(1, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		what++;
		n++;
	}
	else if (0 > n && n > -2147483648)
		what = 2;
	if (what > 0)
	{
		n *= -1;
		*flag = write(1, "-", 1);
		if (*flag == -1)
			return (0);
	}
	count = numprint(n, what, flag);
	return (count);
}

int	ft_printunsigned(unsigned int n, int *flag)
{
	int	count;

	if (n == 0)
	{
		*flag = write(1, "0", 1);
		return (1);
	}
	count = unsigned_numprint(n, flag);
	return (count);
}

int	ft_hex(unsigned int i, int what, int *flag, const char *hex)
{
	char		p[9];
	int			count;

	count = 0;
	if (i == 0)
	{
		*flag = write(1, "0", 1);
		return (1);
	}
	while (i != 0)
	{
		p[count] = hex[i % 16];
		i /= 16;
		count++;
	}
	p[count] = '\0';
	if (what == 1)
		ft_upper(p);
	while (--count >= 0)
	{
		*flag = write(1, &p[count], 1);
		if (*flag == -1)
			break ;
	}
	return (ft_strlen(p));
}
