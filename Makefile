# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:54:29 by daguilar          #+#    #+#              #
#    Updated: 2023/12/11 18:08:46 by daguilar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	erros.c	libft_utils.c new_stack.c node_utils.c nodeA.c nodeB.c operations_1.c \
				operations_2.c operations_3.c operations_4.c push_swap.c sort_stack.c sort_three.c \
				split_ps.c stack_utils.c \
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= pushswap.a

all:			$(NAME)

$(NAME):		$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re