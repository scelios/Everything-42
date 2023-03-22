NAME = pipex

# directories
OBJ_DIR = obj/
SRC_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/

# complier
CFLAGS =	-Wall -Werror -Wextra

# src & obj files
SRC_FILES = pipex.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# libraries
LIBFT = ft

INCLUDES = -I $(LIBFT_DIR)includes/ -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@gcc $(NAME) $(OBJ) -o pipex

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) $(INCLUDES) -c $^
	@mv -f *.o $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST)

re: fclean all

norm:
	@norminette | grep Error

.PHONY: all clean fclean re $(NAME) norm

