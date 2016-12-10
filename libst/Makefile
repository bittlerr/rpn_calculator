# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccuciurc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/06 16:26:24 by ccuciurc          #+#    #+#              #
#    Updated: 2016/12/08 17:45:16 by ccuciurc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libst.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = *.o
all: $(NAME)

$(NAME):
	$(CC) -c $(FLAGS) *.c
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean
