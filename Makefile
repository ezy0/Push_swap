# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 10:48:27 by migmoren          #+#    #+#              #
#    Updated: 2023/08/16 12:44:02 by migmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Wextra -Werror -g -fsanitize=address

INCLUDE = -Llibft -lft -I ./

SRC = main.c ft_handler.c ft_utils.c swap.c push.c rotate.c reverse.c sort.c \
	ft_radix_conversion.c small_sort.c
OBJS = ${SRC:.c=.o}

%.o: %.c libft/libft.a
	${CC} $< -c -o $@

all: libft ${NAME}

libft:
	@make bonus -C libft

${NAME}: ${OBJS} 
	${CC} ${SRC} ${INCLUDE} -o ${NAME}

clean:
	@make clean -C libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C libft
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re libft