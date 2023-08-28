# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 10:37:27 by aguyon            #+#    #+#              #
#    Updated: 2023/08/28 22:58:57 by aguyon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	allocation.c \
		allocation_utils.c

HEADER =	allocation.h

OBJ = $(SRC:.c=.o)

NAME = liballoc.a

CC = cc

CFLAGS =	-Wall -Wextra -Werror

CFLAGSDEV = -Wall -Wextra -Werror -g3

.c.o:
	$(CC) $(CFLAGSDEV) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HEADER)
			ar rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
