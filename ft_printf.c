/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:33:54 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/12 16:59:41 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
	va_list lst;
	int		count;
	int		i;

	count = 0;
	i = 0;

	if (str[i] == '%')
	{
	}
	va_start(lst,str);
	va_arg(lst, int);
	va_end(lst);
	return (1);
}
