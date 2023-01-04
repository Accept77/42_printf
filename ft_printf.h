/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:30:17 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/04 17:48:29 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnbr(int n);
size_t	ft_strlen(const char *str);
int		ft_hex(unsigned int i, int flag);
int		ft_toupper(int c);
int		ft_printunsigned(unsigned int n);
int		ft_printaddress(void *addr);
#endif
