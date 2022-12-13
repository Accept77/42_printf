# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:00:00 by jinsyang          #+#    #+#              #
#    Updated: 2022/12/13 15:59:02 by jinsyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_M = ft_hex.c ft_printaddress.c ft_printchar.c ft_printf.c ft_printnbr.c ft_printstr.c ft_printunsigned.c ft_strlen.c ft_toupper.c

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
