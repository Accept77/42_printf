# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:00:00 by jinsyang          #+#    #+#              #
#    Updated: 2023/02/26 13:19:47 by jinsyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_M = ft_printaddress.c ft_printf_char.c ft_printf.c ft_printf_nbr.c

OBJ_M = $(SRC_M:.c=.o)

OBJ = $(OBJ_M)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rsc $@ $^

all : $(NAME)

clean:
	rm -rf $(OBJ_M)

fclean: clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re all
