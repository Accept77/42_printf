/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:33:54 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/12 19:49:20 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_what(va_list lst, int i, const char *str)
{
	int	count;

	count = 0;
	if (str[i + 1] == 'c')
		count = ft_printchar(va_arg(lst, int));
	else if (str[i + 1] == 's')
		count = ft_printstr(va_arg(lst, char *));
	else if (str[i + 1] == 'p')
		count = ft_printaddress(va_arg(lst, void *));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count = ft_printnbr(va_arg(lst, int));
	else if (str[i + 1] == 'u')
		count = ft_printunsigned(va_arg(lst, unsigned int));
	else if (str[i + 1] == 'x')
		count = ft_hex(va_arg(lst, unsigned int), 0);
	else if (str[i + 1] == 'X')
		count = ft_hex(va_arg(lst, unsigned int), 1);
	else if (str[i + 1] == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_print_what(lst, i, str);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(lst);
	return (count);
}
