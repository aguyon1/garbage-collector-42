# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 10:37:27 by aguyon            #+#    #+#              #
#    Updated: 2023/08/05 10:39:30 by aguyon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = garbage_collector.c \
	  garbage_collector_utils.c

HEADER = garbage_collector.h

OBJ = $(SRC:.c=.o)

NAME = libgc.a

CC = cc

CFLAGS =	-Wall -Wextra -Werror

CFLAGSDEV = -Wall -Wextra -Werror -g3

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HEADER)
			ar rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
