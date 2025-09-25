# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 00:51:28 by oel-mado          #+#    #+#              #
#    Updated: 2025/09/25 03:44:34 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -lpthread

OBJ = ${SRC:.c=.o}

SRC = philo.c\
	is_error.c\
	ft_atoi.c\

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

f: fclean

.PHONY: all clean fclean re f
