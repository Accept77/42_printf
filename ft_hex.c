/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:28:15 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/16 18:41:37 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_hex(unsigned int i, int flag2, int *flag, const char *hex)
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
	if (flag2 == 1)
		ft_upper(p);
	while (--count >= 0)
	{
		*flag = write(1, &p[count], 1);
		if (*flag == -1)
			break ;
	}
	return (ft_strlen(p));
}
