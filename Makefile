# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 11:11:01 by mli               #+#    #+#              #
#    Updated: 2019/11/12 13:30:18 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_FILES = test.c

OBJS = ${SRCS_FILES:.c=.o}

$(NAME): ${OBJS} ${LIBFT}
	ar rcs ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
	make -C ./libft/

all: ${NAME}

clean:
	rm -rf ${OBJS}
	make -C ./libft clean

fclean:
	rm -rf ${NAME} ${OBJS}
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
