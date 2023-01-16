/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:03 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/16 18:25:42 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s, int *flag)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		*flag = write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		*flag = write(1, &s[i], 1);
		if (*flag == -1)
			break ;
		i++;
	}
	return (i);
}
