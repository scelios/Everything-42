NAME = philo

SRCS = ${shell find ./srcs -iname "*.c"}

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	# @${MAKE} -C ./libft./libft/libft.a -o
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}


clean:
	# @${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
