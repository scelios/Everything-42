# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beaudibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 18:03:12 by beaudibe          #+#    #+#              #
#    Updated: 2022/11/17 08:53:29 by beaudibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out

SRCS		=	get_next_line.c get_next_line_utils.c main.c
OBJS		=	${SRCS:.c=.o}

BONUS		=	get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c main.c
BONUS_OBJS		=	$(BONUS:.c=.o)
INCLUDES	=	.get_next_line.h

CC		=	gcc

CFLAGS		=	-Wall -Werror -Wextra -g -D BUFFER_SIZE=13

RM		=	rm -f

${NAME}		:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all		:	${NAME}

.c.o		:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

clean		:
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${OBJS} ${NAME}

bonus			:	$(OBJS) $(BONUS_OBJS)
					ar rcs $(NAME) $(BONUS_OBJS)

re		:	fclean all


.PHONY		:	clean fclean all re
