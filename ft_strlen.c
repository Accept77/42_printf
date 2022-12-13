/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:32:00 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/13 11:48:26 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (count);
	while (str[count])
		count++;
	return (count);
}
