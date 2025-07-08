NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = init.c init2.c philo.c routine.c utils.c allocation.c 

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c philosopher.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all