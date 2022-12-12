# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 17:31:22 by jinsyang          #+#    #+#              #
#    Updated: 2022/12/12 19:55:45 by jinsyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_M : ft_hex.c ft_printaddress.c ft_printchar.c ft_printf.c ft_printnbr.c ft_printstr.c ft_printunsigned.c ft_strlen.c ft_toupper.c

SRC_B = 

OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

ifdef WITH_BONUS
	OBJ = $(OBJ_M) $(OBJ_B)
else
	OBJ = $(OBJ_M)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rsc $@ $^

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

clean:
	rm -rf $(OBJ_M) $(OBJ_B)

fclean: clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re all bonus
