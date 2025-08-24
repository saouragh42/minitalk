# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 20:00:22 by saouragh          #+#    #+#              #
#    Updated: 2025/08/05 20:24:20 by saouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  FPRINTF                                     #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIB_PATH = ../libft
LIBFT = ${LIB_PATH}/libft.a
INCLUDES = -I${LIB_PATH}

SRCS = ft_printf.c\
	   ft_print_chars.c\
	   ft_print_number.c\
	   ft_print_unsigned.c\
	   ft_print_pointer.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}
	@echo "libftprintf.a created successfully!"

clean :
	rm -rf ${OBJS}
	@echo "Cleaned ftprintf object files."

fclean : clean
	rm -rf ${NAME}
	@echo "Cleaned ftprintf library and libft."

re : fclean all

.PHONY:  all clean fclean re
