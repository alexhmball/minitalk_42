# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 20:26:00 by aball             #+#    #+#              #
#    Updated: 2022/04/17 23:44:00 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ACH = ${shell uname}

NAME = client

NAME2 = server

ifeq (${ACH}, Linux)
SLEEP_s = 0
else
SLEEP_s = 42
endif

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -fr

all: libft ${NAME} ${NAME2}

$(NAME): client.c server.c
		${CC} ${CFLAGS} -D SLEEP=${SLEEP_s} client.c libft/libft.a -o client
		${CC} ${CFLAGS} -D SLEEP=${SLEEP_s} server.c libft/libft.a -o server
libft:
		make -C libft

clean:
		make clean -C libft

fclean:
		make fclean -C libft
		${RM} ${NAME} ${NAME2}

re: fclean all

.PHONY: all libft clean fclean re
