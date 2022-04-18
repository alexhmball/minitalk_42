# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 20:26:00 by aball             #+#    #+#              #
#    Updated: 2022/04/18 01:43:31 by ballzball        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ACH = ${shell uname}

ifeq (${ACH}, Linux)
SLEEP_s = 0
else
SLEEP_s = 42
endif

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -fr

all: libft client server

$(NAME): all

libft:
		make -C libft

client: client.c
		${CC} ${CFLAGS} -D SLEEP=${SLEEP_s} client.c libft/libft.a -o client

server: server.c
		${CC} ${CFLAGS} -D SLEEP=${SLEEP_s} server.c libft/libft.a -o server

clean:
		make clean -C libft

fclean:
		make fclean -C libft
		${RM} client server

re: fclean all

.PHONY: all libft clean fclean re
