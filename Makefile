# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 11:11:01 by mli               #+#    #+#              #
#    Updated: 2020/03/12 18:33:09 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_FILES = ft_memset.c ft_bzero.c ft_strlen.c ft_toupper.c ft_tolower.c \
             ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
             ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
             ft_isascii.c ft_isprint.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
             ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
             ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
             ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
             ft_putchar.c ft_putstr.c ft_putnbr.c \
             ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c \
             ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
             ft_strcmp.c ft_memalloc.c ft_free.c ft_atoi_ptr.c
LIBFT_SRCS = ${addprefix ./meine_liebe/, ${LIBFT_FILES}}

SRCS_FILES = ft_printf.c ftpf_argsfill.c ft_itoa_base_lpos.c ftpf_diux.c \
			 ftpf_csp.c ftpf_write.c \
			 ${LIBFT_SRCS}

OBJS = ${SRCS_FILES:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
