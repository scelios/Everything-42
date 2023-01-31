NAME_SERVER = server
NAME_CLIENT = client

# directories
OBJ_DIR = obj/
SRC_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/

# complier
CFLAGS = #-g -Wall -Werror -Wextra

# src & obj files
SRCS_SERVER:= server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT:= client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# libraries
LIBFT = ft

INCLUDES = -I $(LIBFT_DIR)includes/ -I includes/

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME_CLIENT)
	@gcc $(NAME_CLIENT) $(OBJS_CLIENT) -o client

$(NAME_SERVER): $(OBJS_SERVER)
	$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME_SERVER)
	@gcc $(NAME_SERVER) $(OBJS_SERVER) -o server

$(OBJS_SERVER): $(SRCS_SERVER)
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) $(INCLUDES) -c $^

$(OBJS_CLIENT): $(SRCS_CLIENT)
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) $(INCLUDES) -c $^

bonus: all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@/bin/rm -f $(TEST)

re: fclean all bonus

norm:
	@norminette | grep Error

.PHONY: all clean fclean re $(NAME) norm
