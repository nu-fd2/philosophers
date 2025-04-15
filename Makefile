
NAME = philo

CFLAGS = -Wall -Wextra -Werror -lpthread

OBJ = ${SRC:.c=.o}

SRC = philo/philo.c\
	philo/is_error.c\
	philo/valid_args.c\

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o = %.c philo/philo.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re philo
