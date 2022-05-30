# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfidan <mfidan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 17:31:41 by mfidan            #+#    #+#              #
#    Updated: 2022/04/25 17:31:44 by mfidan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
