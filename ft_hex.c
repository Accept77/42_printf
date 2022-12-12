/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:28:15 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:08 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_upper(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		p[i] = ft_toupper(p[i]);
		i++;
	}
}

int	ft_hex(unsigned int i, int flag)
{
	const char	*hex;
	char		p[9];
	int			count;

	hex = "0123456789abcdef";
	count = 0;
	while (i != 0)
	{
		p[count] = hex[i % 16];
		i /= 16;
		count++;
	}
	p[count] = '\0';
	--count;
	if (flag == 1)
		ft_upper(p);
	while (count >= 0)
	{
		write(1, &p[count], 1);
		count--;
	}
	return (ft_strlen(p));
}
