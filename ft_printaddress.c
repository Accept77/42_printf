/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:51 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/12 16:55:16 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printaddress(void *addr)
{
	unsigned long long	i;
	int					count;

	count = 0;
	i = (unsigned long long)addr;
	write(1, "0x10", 4);
	count = ft_hex(i, 0);
	count += 4;
	return (count);
}
