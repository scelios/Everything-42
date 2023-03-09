NAME	=	philo
LIBFT	=	./libft/
HEADERS	=	-I./includes/  -I${LIBFT}/includes
SRCS	=	${shell find ./srcs -iname "*.c"}
OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=
RM		=	rm -f

all: libft ${NAME}

libft:
		make -C ${LIBFT}


%.o: %.c
		${CC} ${CFLAGS} -c ${HEADERS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
		${RM} ${OBJS}
		make -C ${LIBFT} clean

fclean: clean
		${RM} ${NAME}
		make -C ${LIBFT} fclean

pop:
		${RM} ${OBJS}
		${RM} ${NAME}

re: clean all

.PHONY: all, clean, fclean, re, libft
