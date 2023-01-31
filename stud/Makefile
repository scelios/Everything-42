SOURCES = server.c client.c
SERVER	=$(server.c=.o)
CLIENT	= $(client.c=.o)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: $(SERVER) libft
	$(CC) -o $@ $< -Llibft -lft

client: $(CLIENT) libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
