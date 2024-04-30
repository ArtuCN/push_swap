# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconti <aconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:07:02 by aconti            #+#    #+#              #
#    Updated: 2024/03/23 18:49:22 by aconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g

SRCS = median.c norm_utils.c penalty.c check.c init.c cont.c main.c push.c rotate.c sort.c swap.c some_utils.c
OBJ = $(SRCS:.c=.o)

NAME = push_swap

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(DEBUG_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
