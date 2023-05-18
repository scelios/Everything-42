NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx

# NAME	=	fractol
# LIBMLX	=	./lib/MLX42/
# LIBFT	=	./lib/libft/

# HEADERS	=	-I./includes/ -I${LIBMLX}/include -I${LIBFT}/includes
# LIBS	=	-lm -L /Users/${USER}/.brew/opt/glfw/lib/ -lglfw -L${LIBMLX} -lmlx42 -L${LIBFT} -lft
# SRCS	=	${shell find ./srcs -iname "*.c"}
# OBJS	=	${SRCS:.c=.o}

# CC		=	gcc
# CFLAGS	=	-Wall -Wextra -Werror
# RM		=	rm -f

# all: libft libmlx ${NAME}

# libft:
# 		make -C ${LIBFT}

# libmlx:
# 		make -C ${LIBMLX}

# %.o: %.c
# 		${CC} ${CFLAGS} -c ${HEADERS} $< -o ${<:.c=.o}

# ${NAME}: ${OBJS}
# 		${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

# clean:
# 		${RM} ${OBJS}
# 		make -C ${LIBFT} clean
# 		make -C ${LIBMLX} clean

# fclean: clean
# 		${RM} ${NAME}
# 		make -C ${LIBFT} fclean
# 		make -C ${LIBMLX} fclean

# pop:
# 		${RM} ${OBJS}
# 		${RM} ${NAME}

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx, libft
