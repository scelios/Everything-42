
NAME	=	push_swap
SRCS	=	${shell find ./srcs -iname "*.c"}
OBJS	=	${SRCS:.c=.o}

ifeq ($(shell uname), Darwin)
	CC=clang
else
	CC=gcc
endif

all: $(OBJS) libft.o
	$(CC) $(OBJS) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

libft.o: ./libft/libft.a
	$(CC) -c ./libft/libft.a -o libft.o

clean:
	rm -f $(OBJS) libft.o $(NAME)
